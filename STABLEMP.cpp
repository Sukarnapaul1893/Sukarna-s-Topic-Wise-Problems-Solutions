//collected from (https://www.codechef.com/viewsolution/21622517)
#include<bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int tt=0;tt<t;tt++) {
        int n;
        cin >> n;

        int rank_of_man[n+1][n+1];
        int preference_of_man[n+1][n+1];
        int match_of_woman[n+1];
        int match_of_man[n+1];
        int next_propose[n+1];
        bool is_done = false;

        for (int i = 1, q, temp; i <= n; i++) {
            cin >> q;
            for (int j = 1; j <= n; j++) {
                cin >> temp;
                rank_of_man[q][temp] = j;
            }
        }

        for (int i = 1, q, temp; i <= n; i++) {
            cin >> q;
            for (int j = 1; j <= n; j++) {
                cin >> preference_of_man[q][j];
            }
        }


        for (int i = 1; i <= n; i++) {
            next_propose[i] = 1;
            match_of_woman[i] = -1;
            match_of_man[i] = -1;
        }

        int pref_woman, current_suitor;
        while (!is_done) {
            is_done = true;

            for (int i = 1; i <= n; i++) {
                pref_woman = preference_of_man[i][next_propose[i]];
                current_suitor = match_of_woman[pref_woman];

                if (current_suitor != i) {
                    if (current_suitor == -1) {
                        match_of_woman[pref_woman] = i;
                        match_of_man[i] = pref_woman;
                    }
                    else if (rank_of_man[pref_woman][i] < rank_of_man[pref_woman][current_suitor]) {
                        match_of_woman[pref_woman] = i;
                        match_of_man[i] = pref_woman;

                        next_propose[current_suitor]++;
                        match_of_man[current_suitor] = -1;
                        is_done = false;
                    }
                    else {
                        next_propose[i]++;
                        is_done = false;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << i << " " << match_of_man[i] << endl;
        }
    }

    return 0;
}
