// Copyright 2018 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "trie.h"

Trie::Trie() : head_(-1) {}

Trie::~Trie() {
  deleteNodes(head_);
}

void Trie::deleteNodes(TrieNode &root) {
  map<char, TrieNode *> &children = root.children;
  if (children.empty()) {
    return;
  }

  for (map<char, TrieNode*>::iterator it=children.begin(); it!=children.end();
    ++it) {
    deleteNodes(*it->second);
    delete it->second;
  }
  root.children.clear();
}

void Trie::BuildTrie(vector<string> &paths) {
  for(vector<string>::const_iterator e = paths.begin(); e != paths.end(); ++e) {
    Insert(*e);
  }

}
bool Trie::Contains(const string &path) {
  map<char, TrieNode*> *curr = &head_.children;
  if (path.length() == 0) { // return false if input path is empty.
    return false;
  }
  if ((*curr).size() == 0) { // return true if no prefix paths specified.
    return true;
  }

  for(string::const_iterator e = path.begin(); e != path.end(); ++e) {
    const char ch = *e;
    if ((*curr).size() == 0) {
      return true;
    }
    if ((*curr).count(ch) == 0) {
      return false;
    }
    curr = &(*curr)[ch]->children;
  }
  return true;
}

void Trie::Insert(const string &path) {
  map<char, TrieNode*> *curr = &head_.children;
  for(string::const_iterator e = path.begin(); e != path.end(); ++e) {
    const char ch = *e;
    if ((*curr).count(ch) == 0) {
      (*curr)[ch] = new TrieNode(ch);
    }
    curr = &(*curr)[ch]->children;
  }
}
