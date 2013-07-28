#include "bit_vector.h"

#include <algorithm>

namespace seiya {

BitVector::BitVector(size_t size) {
    Init(size);
}

BitVector::~BitVector() {
}

void BitVector::Init(size_t size) {
    size_ = size;
    size_t blocks_size = (size + kBlockSize - 1) / kBlockSize;
    blocks_ = std::vector<uint64_t>(blocks_size, 0);

    //TODO
}

void BitVector::Clear() {
    std::fill(blocks_.begin(), blocks_.end(), 0);
    std::fill(fenwick_.begin(), fenwick_.end(), 0);
}

size_t BitVector::Size() const {
    return size_;
}

size_t BitVector::Count() const {
    if (size_ == 0) {
        return 0;
    } else {
        return FenwickSum(fenwick_.size() - 1);
    }
}

void BitVector::PushBack(int bit) {

}

void BitVector::PopBack() {

}

int BitVector::operator [](size_t id) const {
    return blocks_[id / kBlockSize] >> (id & (kBlockSize - 1)) & 1;
}

void BitVector::SetBit(size_t id, int bit) {

}

uint64_t BitVector::Select(uint64_t bit, uint64_t rank) const {

}

uint64_t BitVector::Rank(uint64_t bit, uint64_t pos) const {

}

std::string BitVector::ToString() const {
    std::string str(size_, '0');
    for (size_t i = 0; i < size_; ++i) {
        if ((*this)[i] == 1) {
            str[i] = '1';
        }
    }
    return str;
}

int BitVector::FenwickSum(int i) const {
    int s = 0;
    for (; p > 0; p -= p & -p) s += _c[p];
    return s;
}

void BitVector::FenwickUpdate(int id, int delta) {
    for (; p <= _n; p += p & -p) _c[p] += d;
}

}  // namespace seiya
