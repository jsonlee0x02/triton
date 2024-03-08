#ifndef TRITON_CONVERSION_TRITONAMDGPU_TO_LLVM_UTILITY_H
#define TRITON_CONVERSION_TRITONAMDGPU_TO_LLVM_UTILITY_H

#include "TritonAMDGPUToLLVM/GCNAsmFormat.h"

#include "mlir/Conversion/LLVMCommon/Pattern.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "triton/Analysis/Utility.h"
#include "triton/Conversion/MLIRTypes.h"
#include "triton/Conversion/TritonGPUToLLVM/Utility.h"
namespace mlir {
namespace LLVM {
using namespace mlir::triton;
namespace AMD {

Value shuffleXor(Location loc, ConversionPatternRewriter &rewriter, Value val,
                 int i);
Value shuffleUp(Location loc, ConversionPatternRewriter &rewriter, Value val,
                int i);
Value shuffleIdx(Location loc, ConversionPatternRewriter &rewriter, Value val,
                 int i);
Value shuffleIdx(Location loc, ConversionPatternRewriter &rewriter, Value val,
                 Value i);

Value llGetPid(int axis, Location loc, ModuleOp moduleOp,
               ConversionPatternRewriter &rewriter);
} // namespace AMD

} // namespace LLVM
} // namespace mlir

#endif
