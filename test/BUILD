cc_test(
    name = "lib-test",
    srcs = ["linked-list-test.cc", "hash-table-test.cc", "array-list-test.cc"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:main",
        "//lib:data-structures",
    ],
)
