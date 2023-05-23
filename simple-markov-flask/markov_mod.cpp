#include <bits/stdc++.h>

using namespace std;

class Markov {
    public:
        map<deque<string>,  vector<string>> state;
        vector<string> all_tokens;
        int state_length;
        Markov(string input_text, int n) {
            ifstream ifile(input_text);
            deque<string> current;
            string buff;
            state_length = n + 1; // n previous states are used
            srand(time(0));
            for (int i = 0; i < state_length; i++) { // placeholder of newlines
                addWord(current, "\n");
            }
            while (ifile >> buff) { // add the main body of the text
                addWord(current, buff);
                all_tokens.push_back(buff);
            }
            addWord(current, "\n"); // mark the end of the text
            ifile.close();
        }

        void generateText(string output_text, int to_generate, int temperature) {
            ofstream ofile(output_text);
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
                    ofile << all_tokens[rand() % n] << " ";
                    i += 1;
                    continue;
                }
                string buff = next[rand() % next.size()];
                if (buff != "\n") {
                    ofile << buff << " ";
                    current.pop_front();
                    current.push_back(buff);
                    i += 1;
                }
            }
            ofile << "\n";
            ofile.close();
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

// word count, states used, temperature, input file, output file
int main(int argc, char *argv[]) {
    Markov chain(argv[4], atoi(argv[2]));
    chain.generateText(argv[5], atoi(argv[1]), atoi(argv[3]));
    return 0;
}
