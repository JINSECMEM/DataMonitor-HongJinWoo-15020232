#include "SampleStore.h"

SampleStore& SampleStore::instance() {
    static SampleStore store;
    return store;
}

SampleStore::SampleStore() {
    samples_ = {
        { 1, "SMP-001", 12.5, 98.2 },
        { 2, "SMP-002", 15.0, 95.7 },
        { 3, "SMP-003", 11.8, 99.1 },
        { 4, "SMP-004", 18.3, 87.4 },
        { 5, "SMP-005", 13.2, 93.6 },
    };
}

const std::vector<Sample>& SampleStore::all() const {
    return samples_;
}

std::optional<Sample> SampleStore::find(int id) const {
    for (const auto& s : samples_)
        if (s.id == id) return s;
    return std::nullopt;
}
