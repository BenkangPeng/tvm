#ifndef TVM_TIR_TRANSFORMS_LOOP_PARTITION_H_
#define TVM_TIR_TRANSFORMS_LOOP_PARTITION_H_

#include <tvm/ir/attrs.h>
#include <tvm/node/node.h>

namespace tvm {
namespace tir {

struct LoopPartitionConfigNode : public tvm::AttrsNode<LoopPartitionConfigNode> {
  bool partition_const_loop;
  bool no_unroll_loop_with_extent_one;
  bool unroll_loop_with_partition_hint_no_interval;

  TVM_DECLARE_ATTRS(LoopPartitionConfigNode, "tir.transform.LoopPartitionConfig") {
    TVM_ATTR_FIELD(partition_const_loop).describe("Split constant loop").set_default(false);
    TVM_ATTR_FIELD(no_unroll_loop_with_extent_one)
        .describe("Don't unroll loops with extent 1")
        .set_default(false);
    TVM_ATTR_FIELD(unroll_loop_with_partition_hint_no_interval)
        .describe("Unroll loops with pragma_loop_partition_hint and no interval")
        .set_default(false);
  }
};

class LoopPartitionConfig : public Attrs {
 public:
  TVM_DEFINE_NOTNULLABLE_OBJECT_REF_METHODS(LoopPartitionConfig, Attrs, LoopPartitionConfigNode);
};

}  // namespace tir
}  // namespace tvm

#endif  // TVM_TIR_TRANSFORMS_LOOP_PARTITION_H_