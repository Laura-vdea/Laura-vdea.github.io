#include <stdio.h>
#include <stdlib.h>

// 람다 함수 매크로
#define lambda(return_type, function_body) ({ \
    return_type __fn__ function_body          \
        __fn__;                               \
})

// Example 구조체 정의
typedef struct
{
    void (*hello_print)();
} Example;

// hello_print 함수 정의
void hello_print()
{
    printf("Hello 한화비전베다!\n");
}

// main 함수
int main()
{
    // Example 구조체 메모리 할당
    Example *example = malloc(sizeof(Example));
    if (!example)
    {
        perror("Failed to allocate memory");
        return 1; // 메모리 할당 실패 시 프로그램 종료
    }

    // hello_print 함수 할당
    example->hello_print = hello_print;

    // 결과 출력
    example->hello_print();

    // 동적 메모리 해제
    free(example);

    return 0;
}