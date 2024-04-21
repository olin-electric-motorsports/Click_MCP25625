cc_library(
    name = "MCP25625",
    srcs = glob(["library/**/*.c"]),
    hdrs = glob(["**/*.h"]),
    strip_include_prefix = "library/include",
    visibility = ["//visibility:public"],
    deps = [
        "//libs/gpio",
        "//libs/spi",
    ],
)
