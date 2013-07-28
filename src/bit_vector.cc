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
}

void BitVector::Clear() {
    std::fill(blocks_.begin(), blocks_.end(), 0);
    std::fill(fenwick_.begin(), fenwick_.end(), 0);
}

size_t BitVector::Size() const {
    return size_;
}

size_t BitVector::Count() const {

}

void BitVector::PushBack() {

}

void BitVector::PopBack() {

}

int BitVector::operator [](size_t index) const {

}

void BitVector::SetBit(size_t index, int bit) {

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

}  // namespace seiya
