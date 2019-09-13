#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 1000000

using namespace std;

const int LOG = log2(MAX)+5;

struct AhoCorasick{
    struct node{
        map<char , int>edge;
        int parent , failLink;
        char ch;
        int counter;

    }d;

    bool bl;
    vector<node>trie;
    vector<string>dictionary;

    void Clear(){
        trie.clear();
        dictionary.clear();
        bl = false;
    }

    AhoCorasick(){
        bl = false;
    }

    void initialization(){
        bl = true;
        d.parent = 0;
        d.ch = 0;
        d.failLink = 0;
        d.counter = 0;
        trie.pb(d);
    }
    void add(string &s){
        dictionary.pb(s);
        int len = s.length();
        int cur = 0;
        for(int i=0; i<len;i++){
            char NOW = s[i] ;
            if(trie[cur].edge.find(NOW)==trie[cur].edge.end()){
                d.parent = cur;
                d.ch = NOW;
                trie.pb(d);
                trie[cur].edge[NOW]=trie.size()-1;
            }
            cur = trie[cur].edge[NOW];
        }
        trie[cur].counter++;
    }
    int goFailure(int idx, char nxt, int depth){
        if(depth<=1)return 0;

        if(trie[idx].edge.find(nxt)==trie[idx].edge.end()){
            if(idx==0)return 0;

            return goFailure(trie[idx].failLink,nxt,depth);
        }
        else{
            return trie[idx].edge[nxt];
        }
    }

    void build(){
        queue<pair<int,int> >q;
        q.push({0,0});
        trie[0].failLink = 0;
        while(!q.empty()){

            int cur = q.front().first;
            int depth = q.front().second;
            q.pop();
            if(cur!=0){
                trie[cur].failLink = goFailure(trie[trie[cur].parent].failLink, trie[cur].ch,depth);
                trie[cur].counter += trie[trie[cur].failLink].counter;
            }
            for(auto v:trie[cur].edge){
                q.push({v.second, depth+1});
            }
        }
    }

    int traverse(string &text){
        int len = text.length();
        int cur =0;
        for(int i=0;i<len;i++){
            char NOW = text[i];
            while(trie[cur].edge.find(NOW)== trie[cur].edge.end()){
                if(cur==0)break;

                cur = trie[cur].failLink;
            }
            if(trie[cur].edge.find(NOW)!=trie[cur].edge.end()){
                cur = trie[cur].edge[NOW];
            }
            if(trie[cur].counter)return true;
        }
        return false;
    }

    int query(string &text){
        return traverse(text);
    }
};

struct dynamicAho{
    AhoCorasick arr[LOG];

    void add(string &pattern){
        int myIdx = -1;
        for(int i=0;i<LOG;i++){
           if(arr[i].dictionary.size()==0){
                myIdx=i;
                break;
           }
        }
        assert(myIdx !=-1);
        arr[myIdx].initialization();
        arr[myIdx].add(pattern);
        for(int j=0;j<myIdx;j++){
            for(auto s:arr[j].dictionary){
                arr[myIdx].add(s);
            }
            arr[j].Clear();
        }
        arr[myIdx].build();
    }

    int query(string &s){
        for(int i=0;i<LOG;i++){
            if(arr[i].bl && arr[i].query(s))return true;
        }
        return false;
    }
}AC;
char s[MAX+10];
int main(){

    int nq;
    scanf("%d",&nq);
    while(nq--){

        int type;
        scanf("%d",&type);
        scanf("%s",s);
        string str=s;
        if(type==0)AC.add(str);
        else{
            if(AC.query(str)){
                puts("YES");
            }
            else{
                puts("NO");
            }
        }
    }
    return 0;


}
