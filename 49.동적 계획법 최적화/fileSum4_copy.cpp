// reference: Garsia–Wachs algorithm
// https://tistory.joonhyung.xyz/15

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <limits>

using namespace std;

struct RankSplayForest {
  typedef int val_t;
  struct node_t {
    int l, r, p;
    int cnt;
    val_t val;
    node_t() :l(-1), r(-1), p(-1), cnt(1) {}
  };
  vector<node_t> nodes;

  RankSplayForest() {}

  void reserve(size_t n) { nodes.reserve(n); }
  val_t& getValue(const int id) { return nodes[id].val; }
};

struct RankSplayTree {
  typedef RankSplayForest::val_t val_t;
  typedef RankSplayForest::node_t node_t;

  RankSplayForest *forest;
  vector<node_t>& nodes;
  int root;

  RankSplayTree(RankSplayForest* forest) : forest(forest), root(-1), nodes(forest->nodes) {}
  RankSplayTree(const RankSplayTree& other) = delete;
  RankSplayTree(RankSplayTree&& other) : forest(other.forest), root(other.root), nodes(other.nodes) { other.root = -1; }
  RankSplayTree &operator =(const RankSplayTree& other) = delete;
  RankSplayTree &operator =(RankSplayTree&& other) { root = other.root; other.root = -1; return *this; }

  int size() const { return root == -1 ? 0 : forest->nodes[root].cnt; }
  void refresh(int v) {
    int cnt = 1;
    int l = nodes[v].l, r = nodes[v].r;
    if (l != -1) cnt += nodes[l].cnt;
    if (r != -1) cnt += nodes[r].cnt;
    nodes[v].cnt = cnt;
  }
  void rotateUp(int v) {
    int p = nodes[v].p;
    bool left = (nodes[p].l == v);
    int s = left ? nodes[v].r : nodes[v].l;
    int g = nodes[p].p;
    nodes[v].p = g;
    nodes[p].p = v;
    if (left) {
      nodes[v].r = p;
      nodes[p].l = s;
    } else {
      nodes[v].l = p;
      nodes[p].r = s;
    }
    if (g == -1) root = v;
    else if (nodes[g].l == p) nodes[g].l = v;
    else nodes[g].r = v;
    if (s != -1) nodes[s].p = p;
  }
  void splay(int x) {
    while (nodes[x].p != -1) {
      int p = nodes[x].p;
      int g = nodes[p].p;
      if (g == -1) {
        rotateUp(x);
        refresh(p);
      } else if ((nodes[g].l == p) == (nodes[p].l == x)) {
        rotateUp(p); rotateUp(x);
        refresh(g);
        refresh(p);
      } else {
        rotateUp(x); rotateUp(x);
        refresh(g); refresh(p);
      }
    }
    refresh(x);
  }
  RankSplayTree splitRight(int id) { // id will remain in the current tree.
    splay(id);
    RankSplayTree right(forest);
    if (root == -1) return right;
    int r = nodes[root].r;
    if (r == -1) return right;
    nodes[root].r = -1;
    refresh(root);
    nodes[r].p = -1;
    right.root = r;
    return right;
  }
  RankSplayTree splitLeft(int id) { // id will remain in the current tree.
    splay(id);
    RankSplayTree left(forest);
    if (root == -1) return left;
    int l = nodes[root].l;
    if (l == -1) return left;
    nodes[root].l = -1;
    refresh(root);
    nodes[l].p = -1;
    left.root = l;
    return left;
  }
  void joinWithRight(RankSplayTree& other) {
    if (root == -1) {
      root = other.root;
      other.root = -1;
      return;
    }
    if (other.root == -1) {
      return;
    }
    int rmost = root;
    int rsub = other.root;
    other.root = -1;
    while (nodes[rmost].r != -1) rmost = nodes[rmost].r;
    splay(rmost);
    nodes[rmost].r = rsub;
    nodes[rsub].p = rmost;
    refresh(rmost);
  }
  int getKth(int k, bool do_splay = true) { // 0-indexed, returns index of the node in `nodes`
    if (k < 0 || root == -1 || k >= nodes[root].cnt) return -1;
    int x = root;
    for (;;) {
      int l = nodes[x].l;
      int r = nodes[x].r;
      if (l != -1) {
        if (nodes[l].cnt > k) {
          x = l;
          continue;
        }
        k -= nodes[l].cnt;
      }
      if (k == 0) {
        if (do_splay) splay(x);
        return x;
      }
      k--;
      x = r;
    }
    return -1;
  }
  void addKth(int k, val_t val) {
    int total_cnt = (root == -1) ? 0 : nodes[root].cnt;
    int newid = static_cast<int>(nodes.size());
    nodes.emplace_back();
    nodes[newid].val = val;
    int rmost;
    if (total_cnt == 0) {
      root = newid;
      splay(root);
      return;
    } else if (k == total_cnt) {
      rmost = root;
    } else {
      int orig = getKth(k, false);
      if (nodes[orig].l == -1) {
        nodes[orig].l = newid;
        nodes[newid].p = orig;
        splay(newid);
        return;
      }
      rmost = nodes[orig].l;
    }
    while (nodes[rmost].r != -1) rmost = nodes[rmost].r;
    nodes[rmost].r = newid;
    nodes[newid].p = rmost;
    splay(newid);
    return;
  }
  void removeId(const int id) {
    const int par = nodes[id].p;
    const int left = nodes[id].l;
    const int right = nodes[id].r;
    if (left == -1) {
      if (right != -1) nodes[right].p = par;
      if (par == -1) root = right;
      else if (nodes[par].l == id) nodes[par].l = right;
      else nodes[par].r = right;
      if (par != -1) splay(par);
      return;
    } else if (right == -1) {
      nodes[left].p = par;
      if (par == -1) root = left;
      else if (nodes[par].l == id) nodes[par].l = left;
      else nodes[par].r = left;
      if (par != -1) splay(par);
      return;
    }
    int replace = left;
    while (nodes[replace].r != -1) replace = nodes[replace].r;
    swap(nodes[id].val, nodes[replace].val);
    removeId(replace);
  }
  val_t& getValue(const int id) { return nodes[id].val; }
};

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  RankSplayForest forest;
  forest.reserve(n * 2);
  RankSplayTree odd(&forest), even(&forest);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i % 2 == 0) even.addKth(i / 2, a[i]);
    else odd.addKth(i / 2, a[i]);
  }
  long long ans = 0;
  {
    int i = 0;
    vector<pair<int, int>> resume_pos; // ops, pos
    int idle = 0;
    for (int ops = 0; ops < n - 1; ops++) {
      for (;;) {
        while (!resume_pos.empty() && resume_pos.back().second + (resume_pos.back().first - ops) <= i) resume_pos.pop_back();
        bool is_even = i % 2 == 0;
        int len = n - ops;
        int idA = is_even ? even.getKth(i / 2) : odd.getKth(i / 2);
        int A = forest.getValue(idA);
        if (i + 2 < len) {
          int C = forest.getValue(is_even ? even.getKth(i / 2 + 1) : odd.getKth(i / 2 + 1));
          if (A > C) {
            idle++;
            if (idle >= 3 && !resume_pos.empty()) {
              idle = 0;
              i = resume_pos.back().second + (resume_pos.back().first - ops);
              resume_pos.pop_back();
            } else {
              i++;
            }
            continue;
          }
        }
        // found op
        idle = 0;
        int idB = is_even ? odd.getKth((i + 1) / 2) : even.getKth((i + 1) / 2);
        int B = forest.getValue(idB);
        if (is_even) even.removeId(idA); else odd.removeId(idA);
        if (is_even) odd.removeId(idB); else even.removeId(idB);
        int sum = A + B;
        ans += sum;
        int p1 = 0, p2 = 0;
        {
          int best_id = -1;
          int sid = even.getKth((i + 1) / 2);
          if (sid != -1) sid = forest.nodes[sid].l;
          else sid = even.root;
          while (sid != -1) {
            if (forest.getValue(sid) >= sum) {
              best_id = sid;
              sid = forest.nodes[sid].r;
            } else {
              sid = forest.nodes[sid].l;
            }
          }
          if (best_id != -1) {
            even.splay(best_id);
            int ind = 0;
            int subl = forest.nodes[best_id].l;
            if (subl != -1) ind = forest.nodes[subl].cnt;
            p1 = ind * 2 + 1;
          }
        }
        {
          int best_id = -1;
          int sid = odd.getKth(i / 2);
          if (sid != -1) sid = forest.nodes[sid].l;
          else sid = odd.root;
          while (sid != -1) {
            if (forest.getValue(sid) >= sum) {
              best_id = sid;
              sid = forest.nodes[sid].r;
            } else {
              sid = forest.nodes[sid].l;
            }
          }
          if (best_id != -1) {
            odd.splay(best_id);
            int ind = 0;
            int subl = forest.nodes[best_id].l;
            if (subl != -1) ind = forest.nodes[subl].cnt;
            p2 = ind * 2 + 1 + 1;
          }
        }
        int newind = max(p1, p2);
        int eRid = even.getKth((newind + 1) / 2);
        int oRid = odd.getKth(newind / 2);
        RankSplayTree eL(&forest), oL(&forest);
        if (eRid != -1) { eL = even.splitLeft(eRid); }
        else eL = move(even);
        if (oRid != -1) { oL = odd.splitLeft(oRid); }
        else oL = move(odd);
        if (newind % 2 == 0) eL.addKth(newind / 2, sum);
        else oL.addKth(newind / 2, sum);
        eL.joinWithRight(odd);
        oL.joinWithRight(even);
        odd = move(oL);
        even = move(eL);
        resume_pos.emplace_back(ops, max(0, i - 2));
        i = max(0, max(p1, p2) - 2);
        break;
      }
    }
  }
  printf("%lld\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; testcase++) {
    solve();
  }
  return 0;
}
