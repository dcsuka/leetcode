from collections import Counter
from typing import List
import re

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        word_length, num_words, ret, matches = len(words[0]), len(words), [], []
        regex = '|'.join(set(words))
        matches = [(mat.group(1), mat.start()) for mat in re.finditer(f"(?<!{regex})(?=(({regex})+))", s)]
        for x, start in matches:
            trial = [x[i:i+word_length] for i in range(0, len(x), word_length)]
            end = num_words
            while end <= len(trial):
                test = trial[end-num_words:end]
                if Counter(test) == Counter(words):
                    ret.append(start+(end-num_words)*word_length)
                end += 1
        if len(set(s)) == 1 and ret:
            ret = list(range(0, max(ret)+1))
        return ret