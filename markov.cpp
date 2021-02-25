#include <bits/stdc++.h>

using namespace std;

class Markov {
    public:
        map<deque<string>,  vector<string>> state;
        vector<string> all_tokens;
        int state_length;
        Markov(string input_text, int n) {
            ifstream file(input_text);
            deque<string> current;
            string buff;
            state_length = n + 1; // n previous states are used
            srand(time(0));
            for (int i = 0; i < state_length; i++) { // placeholder of newlines
                addWord(current, "\n");
            }
            while (file >> buff) { // add the main body of the text
                addWord(current, buff);
                all_tokens.push_back(buff);
            }
            addWord(current, "\n"); // mark the end of the text
            file.close();
        }

        void generateText(int to_generate, int temperature) {
            deque<string> current;
            string buff;
            int n = all_tokens.size();
            int i = 0;
            for (int i = 0; i < state_length; i++) { // placeholder of newlines
                addWord(current, "\n");
            }
            while (i < to_generate) {
                vector<string>& next = state[current];
                if ((rand() % 100 + 1) <= temperature) { // introduce a little anarchy
                    cout << all_tokens[rand() % n] << " ";
                    i += 1;
                    continue;
                }
                string buff = next[rand() % next.size()];
                if (buff != "\n") {
                    cout << buff << " ";
                    current.pop_front();
                    current.push_back(buff);
                    i += 1;
                }
            }
            cout << "\n";
        }
    private:
        void addWord(deque<string>& current, string extend) {
            if ((int) current.size() == state_length) {
                state[current].push_back(extend);
                current.pop_front();
            }
            current.push_back(extend);
        }
};
