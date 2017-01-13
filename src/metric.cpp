#include "metric.hpp"
#include <string>
#include <vector>

using namespace std;

munits::Metric::Metric(vector<int> dim_vector, string base_unit, set<string> remove,
                       const map<string, const shared_ptr<munits::Unit>> additional_units,
                       const map<const string, const string> resolver):
        dim_vector(dim_vector),
        converter(make_shared<Converter>(base_unit, remove, additional_units)),
        unit_resolve_mapping(resolver)
        {};
