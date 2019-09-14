#include<bits/stdc++.h>

using namespace std;
const int MAXL = 1<<17;
const int MAXN = 1<<10;

int N;
char text[MAXL];
char buf[MAXL];
bool substr[MAXN];

int root , nodes;

struct trieNode{
    bool visited;
    int matchFail;
    vector<int >matches;
    int fail;
    map<char , int >next;
}trie[MAXL];

void insert(char *s, int wordId){
    int x = root;
    for(int i=0;s[i];++i){

        int &nxt = trie[x].next[s[i]];
        if(!nxt)nxt = ++nodes;
        x = nxt;
    }
    trie[x].matches.push_back(wordId);
}

int target(int x, char ch){
    while(x && !trie[x].next.count(ch)){
        x = trie[x].fail;
    }

    return x ? trie[x].next[ch] : root;
}

void bfs(){
    trie[root].fail = 0;

    queue<int>q;
    q.push(root);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto it = trie[u].next.begin(); it!= trie[u].next.end();it++){
            char ch = (*it).first;
            int v = (*it).second;

            int f = target(trie[u].fail, ch);

            trie[v].fail = f;
            trie[v].matchFail = trie[f].matches.empty() ? trie[f].matchFail : f;

            q.push(v);
        }

    }
}

void search(){
    int x = root ;
    for(int i=0; text[i];i++){
        x =target(x,text[i]);
        for(int t =x; t && !trie[t].visited; t = trie[t].matchFail){

            trie[t].visited = true;
            for(auto j=0;j<trie[t].matches.size();j++){
                substr[trie[t].matches[j]]=true;
            }
        }
    }
}
int main(){
    root = ++nodes;

    scanf("%s", &text);
    scanf("%d", &N);

    for(auto i=0;i<N;i++){

        scanf("%s",&buf);
        insert(buf,i);
    }
    bfs();
    search();

    for(auto i=0;i<N;i++){
        printf("%s\n", substr[i] ? "Y" : "N");

    }

    return 0;
}
