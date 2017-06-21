//https://codefights.com/interview-practice/task/pMvymcahZ8dY4g75q/description
//frankr@coj

const int msk = (1 << 18) - 1;
const int mkBit = (1 << 20);

int getValueAt(std::vector<int>& a, int pos) {
    return a[pos] & msk;
}

bool isValueMarked(std::vector<int>& a, int value) {
    value--;
    return (a[value] & mkBit) != 0;
}

void markValue(std::vector<int>& a, int value) {
    value--;
    a[value] |= mkBit;
}

int firstDuplicate(std::vector<int> a) {
    int value;
    for (int i = 0 ; i < a.size() ; i++) {
        value = getValueAt(a, i);
        if (isValueMarked(a, value))
            return value;
        markValue(a, value);
    }
    
    return -1;
}

