#pragma once

#include <vector>
#include <string>

namespace seiya {

class BitVector {
public:
    BitVector(size_t size = 0);
    ~BitVector();

    void Init(size_t size);
    void Clear();

    size_t Size() const;
    size_t Count() const;

    void PushBack(int bit);
    void PopBack();

    int operator [](size_t id) const;
    void SetBit(size_t id, int bit);

    uint64_t Select(uint64_t bit, uint64_t rank) const;
    uint64_t Rank(uint64_t bit, uint64_t pos) const;

    std::string ToString() const;

private:
    static const size_t kBlockSize = 64;

    int FenwickSum(int id) const;
    void FenwickUpdate(int id, int delta);

    size_t size_;
    std::vector<uint64_t> blocks_;
    std::vector<int> fenwick_;
};

}  // namespace seiya
