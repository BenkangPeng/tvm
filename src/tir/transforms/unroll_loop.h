#ifndef TVM_TIR_TRANSFORMS_UNROLL_LOOP_H_
#define TVM_TIR_TRANSFORMS_UNROLL_LOOP_H_
#include <tvm/ir/attrs.h>
#include <tvm/node/node.h>

namespace tvm {
namespace tir {
struct UnrollLoopConfigNode : public tvm::AttrsNode<UnrollLoopConfigNode> {
  int auto_max_step;
  int auto_max_depth;
  int auto_max_extent;
  int explicit_unroll;
  int unroll_local_access;

  TVM_DECLARE_ATTRS(UnrollLoopConfigNode, "tir.transform.UnrollLoopConfig") {
    TVM_ATTR_FIELD(auto_max_step)
        .describe("Threshold of number of steps in the loop to be automatically unrolled")
        .set_default(0);
    TVM_ATTR_FIELD(auto_max_depth)
        .describe("The maximum nested level of loops that can be automatically unrolled.")
        .set_default(8);
    TVM_ATTR_FIELD(auto_max_extent)
        .describe("The maximum extent of loop that will be unrolled.")
        .set_default(0);
    TVM_ATTR_FIELD(explicit_unroll)
        .describe("Whether to explicitly unroll the loop instead of setting a pragma")
        .set_default(true);
    TVM_ATTR_FIELD(unroll_local_access)
        .describe("Whether to always unroll local access")
        .set_default(false);
  }
};

class UnrollLoopConfig : public Attrs {
 public:
  TVM_DEFINE_NOTNULLABLE_OBJECT_REF_METHODS(UnrollLoopConfig, Attrs, UnrollLoopConfigNode);
};
}  // namespace tir
}  // namespace tvm

#endif  // TVM_TIR_TRANSFORMS_UNROLL_LOOP_H_