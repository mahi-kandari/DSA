class MedianFinder {
public:
    multiset<int> mt1;
    multiset<int> mt2;

    MedianFinder() {}

    void addNum(int num) {

        mt2.insert(num);

        mt1.insert(*mt2.begin());
        mt2.erase(mt2.begin());

        if (mt1.size() > mt2.size()) {
            mt2.insert(*mt1.rbegin());
            mt1.erase(prev(mt1.end()));
        }
    }

    double findMedian() {
        if ((mt1.size() + mt2.size()) % 2 == 0) {

            return (*mt1.rbegin() + *mt2.begin()) / 2.0;
        } else {
            return *mt2.begin();
        }
    }
};