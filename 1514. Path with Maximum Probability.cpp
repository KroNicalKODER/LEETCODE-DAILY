class Solution {
public:

    double dijkshtra(vector<vector<pair<int,double>>>& graph,int n,int start,int end) {
        set<pair<double,int>> se;
        se.insert({0,start});
        vector<double> prob(n,INT_MAX);
        while(!se.empty()){
            pair<double,int> curr = *(se.begin());
            se.erase(se.begin());
            int dest = curr.second;
            double wt = curr.first;

            for(auto child:graph[dest]){
                if(child.second + wt < prob[child.first]){
                    auto ch = se.find({prob[child.first],child.first});
                    if(ch!=se.end()) se.erase(ch);
                    prob[child.first] = child.second + wt;
                    se.insert({prob[child.first],child.first});
                }
            }
        }
        return -prob[end];
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> graph(n);
        int sz = edges.size();
        for(int i=0;i<sz;i++){
            succProb[i] = -log10(succProb[i]);
        }
        for(int i=0;i<sz;i++) {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});

        }        
        return pow(10,dijkshtra(graph,n,start,end));
    }
};
