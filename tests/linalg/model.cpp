#include <map>

#include "viennacl/vector.hpp"

#include <memory>
#include "isaac/model/import.hpp"

namespace isc = isaac;

int main()
{
  viennacl::vector<float> x(10000), y(10000), z(10000);
  std::map<std::string, isc::tools::shared_ptr<isc::model> > models = isc::import("geforce_gt_540m.json");
  models["vector-axpy-float32"]->tune(viennacl::symbolic_expression(z, viennacl::op_assign(), x));
  models["vector-axpy-float32"]->execute(viennacl::symbolic_expression(z, viennacl::op_assign(), x));
  return EXIT_SUCCESS;
}
