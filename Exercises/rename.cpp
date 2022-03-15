//
// Created by PayThePizzo on 3/15/2022.
//

#include <vector>
#include <optional>
#include <algorithm>
#include <iostream>
#include <climits>

// https://moodle.unive.it/mod/assign/view.php?id=444949

std::optional<std::pair<int, int>> unione(const std::vector<std::pair<int, int>>& arr) {
    auto [start, stop] = arr[0];
    for (const auto &[a, b] : arr) {
        if (a - 1 <= stop && b + 1 >= stop) {
            stop = b;
        } else {
            return std::nullopt;
        }
    }

    return std::make_pair(start, stop);
}

int scarto(std::vector<int> punteggi) {
    std::sort(punteggi.begin(), punteggi.end());

    int r = 0;

    auto end = punteggi.end();
    for (auto it = punteggi.begin(); it < end; it++) {
        r += *std::next(it) - *it;
    }

    return r;
}

// https://moodle.unive.it/mod/page/view.php?id=420498

std::pair<int, int> findMaxTreasure(const std::vector<std::vector<int>> &map) {
    auto size = map.size();

    const auto isLocalMax = [&map, size](int i, int j) {
        auto cur = map[i][j];
        if (i > 0        && cur < map[i - 1][j]) return false;
        if (i < size - 1 && cur < map[i + 1][j]) return false;
        if (j > 0        && cur < map[i][j - 1]) return false;
        if (j < size -1  && cur < map[i][j + 1]) return false;
        return true;
    };

    int mi = 0;
    int mj = 0;
    int m = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (isLocalMax(i, j) && m < map[i][j]) {
                m = map[i][j];
                mi = i;
                mj = j;
            }
        }
    }

    return std::make_pair(mi, mj);
}

// https://moodle.unive.it/mod/page/view.php?id=266066

std::tuple<int, int, int> maxGuadagno(const std::vector<int> &v) {
    int mi = 0;
    int mj = 0;
    int m = 0;

    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i; j < v.size(); j++) {
            if (v[j] - v[i] > m) {
                m = v[j] - v[i];
                mi = i;
                mj = j;
            }
        }
    }

    return std::make_tuple(mi, mj, v[mj] - v[mi]);
}

// https://moodle.unive.it/mod/page/view.php?id=281956

int contaCoppie(std::vector<int> v, int profittoProg) {
    std::sort(v.begin(), v.end());

    int r = 0;

    auto end = v.end();
    for (auto it = v.begin(); it < end; it++) {
        for (auto jt = std::next(it); jt < end; jt++) {
            if (*it + *jt == profittoProg) {
                r += 1;
                v.erase(jt);
            }
        }
    }

    return r;
}

int main() {
    if (auto r = unione({std::make_pair(-1, 1), std::make_pair(2, 4)})) {
        auto [a, b] = *r;
        std::cout << a << " " << b << std::endl;
    } else {
        std::cout << "err" << std::endl;
    }

    auto s = scarto({3, 2, 6, 3, 1, 3});
    std::cout << s << std::endl;

    auto [a, b] = findMaxTreasure({
                                          {10,  8, 10, 10},
                                          {14, 13, 12, 11},
                                          {21,  9, 11, 16},
                                          {15, 17, 19, 20},
                                  });
    std::cout << a << " " << b << std::endl;

    auto [start, stop, v] = maxGuadagno({2, 4, 3, 0, 7, 4, 6, 1, 10, 2, 7, 15, 3});
    std::cout << start << " " << stop << " " << v << std::endl;

    auto r = contaCoppie({5, 7, 9, 13, 11, 6, 6, 3, 3}, 12);
    std::cout << r << std::endl;
}