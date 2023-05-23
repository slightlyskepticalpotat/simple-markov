# simple-markov
A simple and fast [Markov Chain](https://en.wikipedia.org/wiki/Markov_chain)-based text generator in C++, with a partial Flask frontend [here](https://github.com/slightlyskepticalpotat/simple-markov/tree/main/simple-markov-flask). It reads space-delimited tokens from a text file, and can be used to generate individual words or letters in sequence. The number of previous states used, number of words to generate, and temperature (how "random" the generated text is) are all configurable. A text file of Shakespeare's plays and sonnets has been included for convenience. Here is some annotated example code:
```cpp
int main() {
    cin.tie(0)->sync_with_stdio(0); // speeds up i/o
    Markov chain("shakespeare.txt", 1); // name of the text file, previous states used
    chain.generateText(256, 5); // number of words to generate, temperature from 0-100
    return 0;
}
```

The code could generate the following text when run:
```
THE SONNETS by William Shakespeare
From fairest creatures we desire increase,
That thereby beauty's should rose might never die,
But if the while I think proceeds.
Thine eyes I love, and love are still my argument:
So all my vows are oaths lips but to misuse thee:
And all those friends which I compile, confounds
Whose influence is thine, and it born of o'ertake love?
Then gentle cheater urge not my measure,
All these I better in one of thine, from that which it contains,
And that thou forget'st so long,
To speak of that which thou hast taste, too grossly dyed.
The lily I condemned for thy sake.
For thee watch I, whilst thou dost wake elsewhere,
From me far off, with others all too near.
Sin of self-love possesseth all mine eye,
As interest of the time,
And see thy blood warm when thou shalt strangely pass,
And scarcely greet me with that which it was nourished by.
This thou perceiv'st, which makes thy love though much, is not all my best doth worship thy defect,
For far slander's mark was ever yet the fair,
The ornament of beauty is suspect,
A crow that flies in heaven's air: did
Let them say more that like of hearsay well, I will excuse ye,
Thou call dost love her, because thou know'st to my sportive blood?
Or on my love is as gust a death which cannot choose
But weep to have, that which thou deserv'st alone:
O absence what a happy title do I now
```
