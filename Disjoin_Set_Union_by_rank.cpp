#include<iostream>
#include<vector>
using namespace std;
class disjoint_set{
    public:
    vector<int> rank,par;
    disjoint_set(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i] = i;
        }
    }
    int find_ulti_par(int node){
        if(node == par[node]){
            return node;
        }
        return par[node] = find_ulti_par(par[node]);
    }

    void union_by_rank(int u, int v){
        int ulp_u = find_ulti_par(u);
        int ulp_v = find_ulti_par(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u]>rank[ulp_v]){
            par[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v]>rank[ulp_u]){
            par[ulp_u] = ulp_v;
        }
        else{
            par[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};
int main(){
    disjoint_set ds(7);
    ds.union_by_rank(1,2);
    ds.union_by_rank(2,3);
    ds.union_by_rank(4,5);
    ds.union_by_rank(6,7);
    ds.union_by_rank(5,6);
    if(ds.find_ulti_par(1) == ds.find_ulti_par(7)) cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
    ds.union_by_rank(3,7);
    if(ds.find_ulti_par(1) == ds.find_ulti_par(7)) cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
    cout<<"Succesfully executed"<<endl;
    return 0;
}