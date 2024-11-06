// Generate 'bullshit sentences'
// TO DO 1: In lines v=, n=, a=, ... rand%12? Why always 12?
// TO DO 2: Create more complex sentences e.g. by using more adjectives together
// or by concatenating several phrases. TO DO 3: Generalize the 'You should' by
// allowing other random introductions, e.g. "we have to", "our company must" TO
// DO 4: Don't write the output to the screen but copy the whole phrase into a
// separate string (without using library functions) Source of words see:
// http://dack.com/web/bullshit.html

#include <stdio.h>
#include <stdlib.h>

int main() {
  char verbs[][20] = {"benchmark", "exploit",  "facilitate",  "generate",
                      "implement", "leverage", "maximize",    "mesh",
                      "monetize",  "optimize", "orchestrate", "redefine"};
  char nouns[][20] = {"action-items",    "applications",  "bandwidth",
                      "communities",     "e-business",    "experiences",
                      "infrastructures", "methodologies", "partnerships",
                      "synergies",       "solutions",     "technologies"};
  char adjectives[][20] = {
      "bleeding-edge",    "collaborative",   "cross-platform", "distributed",
      "efficient",        "global",          "holistic",       "innovative",
      "mission-critical", "next-generation", "out-of-the-box", "user-centric"};
  char beginnings[][100] = {"Your boss says: You have to",
                            "Our company policy needs us to",
                            "It would be a good idea to", "Definetly do not"};

  int number, b, v, n, a;

  printf("How much bullshit do you need?");
  scanf("%d", &number);

  int i, j;

  while (number > 0) {
    b = rand() % 4;
    v = rand() % 12;
    n = rand() % 12;
    a = rand() % 12;

    /* printf("%s %s %s %s and %s %s %s!\n", beginnings[b], verbs[v],
           adjectives[a], nouns[n], verbs[(v + 1) % 12],
           adjectives[(a + 1) % 12], nouns[(n + 1) % 12]); */

    i = 0;
    j = 0;
    char result[1000];

    while (beginnings[b][j] != 0) {
      result[i] = beginnings[b][j];
      i++;
      j++;
    }
    result[i] = ' ';

    j = 0;
    while (verbs[v][j] != 0) {
      result[i] = verbs[v][j];
      i++;
      j++;
    }
    result[i] = ' ';

    j = 0;
    while (adjectives[a][j] != 0) {
      result[i] = adjectives[a][j];
      i++;
      j++;
    }
    result[i] = ' ';

    j = 0;
    while (nouns[n][j] != 0) {
      result[i] = nouns[n][j];
      i++;
      j++;
    }
    result[i] = 0;

    printf("%s\n", result);
    number = number - 1;
  }
}