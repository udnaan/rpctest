struct testxdr {
    long long_arg;
    string string_arg < 128 >;
};

program TEST_PROG {
    version TEST_VERS {
    string STR_TEST(testxdr) = 1;  /* procedure number = 1 */
    } = 1;                          /* version number = 1 */
} = 0x31234567;                     /* program number = 0x31234567 */
