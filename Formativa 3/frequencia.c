#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ascii;
    int freq;
} CharFreq;

int compare(const void *a, const void *b) {
    CharFreq *charFreqA = (CharFreq *)a;
    CharFreq *charFreqB = (CharFreq *)b;
    
    if (charFreqA->freq == charFreqB->freq)
        return charFreqA->ascii - charFreqB->ascii;
    return charFreqA->freq - charFreqB->freq;
}

int main() {
    char line[1001];
    int frequencies[256];
    int first = 1;

    while (fgets(line, sizeof(line), stdin)) {
        memset(frequencies, 0, sizeof(frequencies));
        
        for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
            frequencies[(unsigned char)line[i]]++;
        }

        CharFreq charFreqs[256];
        int count = 0;

        for (int i = 0; i < 256; i++) {
            if (frequencies[i] > 0) {
                charFreqs[count].ascii = i;
                charFreqs[count].freq = frequencies[i];
                count++;
            }
        }

        qsort(charFreqs, count, sizeof(CharFreq), compare);

        if (!first) {
            printf("\n");
        }
        first = 0;

        for (int i = 0; i < count; i++) {
            printf("%d %d\n", charFreqs[i].ascii, charFreqs[i].freq);
        }
    }
    
    printf("\n");
    return 0;
}
