#ifndef BOOST_REAL_INTERVAL_HPP
#define BOOST_REAL_INTERVAL_HPP

#include <vector>

#include <real/boundary.hpp>
#include <real/boundary_helper.hpp>

namespace boost {
    namespace real {

        struct interval {
            boost::real::boundary lower_bound;
            boost::real::boundary upper_bound;

            interval() = default;

            std::string as_sting() const {

                std::string result = "";
                std::string lb = this->lower_bound.as_string();
                std::string ub = this->upper_bound.as_string();

                if (lb == ub) {
                    result = lb;
                } else {
                    result = '[' + lb + ", " + ub + ']';
                }

                return result;
            }

            void swap_bounds() {
                this->lower_bound.swap(this->upper_bound);
            }

            bool operator<(const boost::real::interval& other) const {
                return this->upper_bound < other.lower_bound;
            }

            bool positive() const {
                // If the lower bound of a approximation_interval is positive, then the upper bound is also positive
                // and the approximation_interval is fully contained in the positive number line
                return this->lower_bound.positive;
            }

            bool negative() const {
                // If the upper bound of a approximation_interval is negative, then the lower bound is also negative
                // and the approximation_interval is fully contained in the negative number line
                return !this->upper_bound.positive;
            }

            bool operator==(const boost::real::interval& other) const {
                return this->lower_bound == other.lower_bound && this->upper_bound == other.upper_bound;
            }
        };
    }
}

std::ostream& operator<<(std::ostream& os, const boost::real::interval& interval) {
    return os << interval.as_sting();
}

#endif //BOOST_REAL_INTERVAL_HPP
