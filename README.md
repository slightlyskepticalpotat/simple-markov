# simple-markov
A simple and fast [Markov Chain](https://en.wikipedia.org/wiki/Markov_chain)-based text generator in C++, with a partial Flask frontend [here](https://github.com/slightlyskepticalpotat/chenanthony-markov). It reads space-delimited tokens from a text file, and can be used to generate individual words or letters in sequence. The number of previous states used, number of words to generate, and temperature (how "random" the generated text is) are all configurable. A text file of Shakespeare's plays and sonnets has been included for convenience. Here is some annotated example code:

```c++
int main() {
    ios_base::sync_with_stdio(false); // makes the i/o faster
    cin.tie(NULL); // also makes the i/o faster
    Markov chain("shakespeare.txt", 2); // name of the text file, previous states used
    chain.generateText(128, 2); // number of words to generate, temperature from 0-100
    return 0;
}
```
