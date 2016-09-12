cc_library(
  name = "techq-lib",
  srcs = ["impl.cc"],
  hdrs = ["header.h"],
  deps = [
    "//lib:data-structures"
  ]
)

cc_binary(
  name = "techq",
  srcs = ["main.cc"],
  deps = [
    ":techq-lib"
  ]
)
