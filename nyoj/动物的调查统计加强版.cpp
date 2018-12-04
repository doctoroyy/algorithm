#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node {
  node *next[26];
  int count;
}Trie;
char ch[15];
int max;
node *root;
node* createTrie() {
  node *p;
  p = (node*)malloc(sizeof(node));
  for (int i = 0; i < 26; i++) {
    p->next[i] = NULL;
  }
  p->count = 0;
  return p;
}
void insert(char *str) {
  node *p = root;
  for (int i = 0; str[i]; i++) {
    int c = str[i] - 'a';
    if (p->next[c] == NULL) p->next[c] = createTrie();
    p = p->next[c];
  }
  p->count++;
  if (p->count > max) {
    max = p->count;
    strcpy(ch, str);
  }
}
int main() {
  int t;
  char str[15];
  scanf("%d", &t);
  root = createTrie();
  while (t--) {
    scanf("%s", str);
    insert(str);
  }
  printf("%s %d\n", ch, max);
}
