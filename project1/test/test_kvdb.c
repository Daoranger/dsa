#include "../third_party/unity/unity.h"
#include "../src/kvdb.c"

static struct KeyValue pairs[MAX_PAIRS];

void setUp(void) { memset(pairs, 0, sizeof(pairs)); }
void tearDown(void) {}

void test_set_get(void)
{
    setCmd(pairs, "myKey", "1234");
    struct KeyValue* kv = getCmd(pairs, "myKey");
    TEST_ASSERT_NOT_NULL(kv);
    TEST_ASSERT_EQUAL_STRING("1234", kv->value);
}

void test_get_null(void)
{
    struct KeyValue* kv = getCmd(pairs, "invalidKey");
    TEST_ASSERT_NULL(kv);
}

void test_delete(void)
{
    setCmd(pairs, "tempKey", "99");
    deleteCmd(pairs, "tempKey");
    struct KeyValue* kv = getCmd(pairs, "tempKey");
    TEST_ASSERT_NULL(kv);
}

void test_set_overwrite(void)
{
    setCmd(pairs, "score", "10");
    setCmd(pairs, "score", "20");
    struct KeyValue* kv = getCmd(pairs, "score");
    TEST_ASSERT_NOT_NULL(kv);
    TEST_ASSERT_EQUAL_STRING("20", kv->value);
}

void test_delete_null(void)
{
    // deleteCmd should return false;
    TEST_ASSERT_FALSE(deleteCmd(pairs, "tempKey"));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_set_get);
    RUN_TEST(test_get_null);
    RUN_TEST(test_delete);
    RUN_TEST(test_set_overwrite);
    RUN_TEST(test_delete_null);
    return UNITY_END();
}