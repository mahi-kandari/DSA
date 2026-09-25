class DSU {
public:
    vector<int> par, siz;

    DSU(int n) {
        par.resize(n);
        siz.resize(n);

        for(int i = 0; i < n; i++) {
            par[i] = i;
            siz[i] = 1;
        }
    }

    int findpar(int u) {
        if(par[u] == u)
            return u;

        return par[u] = findpar(par[u]);
    }

    void merge(int u, int v) {
        int paru = findpar(u);
        int parv = findpar(v);

        if(paru == parv)
            return;

        if(siz[paru] >= siz[parv]) {
            par[parv] = paru;
            siz[paru] += siz[parv];
        }
        else {
            par[paru] = parv;
            siz[parv] += siz[paru];
        }
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<tuple<int,int,int>> edges;

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int wt = abs(x1 - x2) + abs(y1 - y2);

                edges.push_back({wt, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        DSU obj(n);

        int ans = 0;

        for(auto [wt, u, v] : edges) {

            int paru = obj.findpar(u);
            int parv = obj.findpar(v);

            if(paru == parv)
                continue;

            obj.merge(u, v);

            ans += wt;
        }

        return ans;
    }
};