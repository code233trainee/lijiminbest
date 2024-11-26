
//编写模拟内存泄漏并占满物理内存的程序需要非常谨慎，因为这样的程序可能会导致系统不稳定，甚至可能会导致数据丢失或者其他不可预料的问题。请在隔离的环境中进行测试，确保不会影响其他进程或重要数据。
//以下是一个简单的 C++ 代码示例，通过在循环中反复分配内存而不释放它，逐渐占用大量系统内存，最后导致系统内存耗尽并崩溃：
#include <iostream>
#include <vector>
#include <thread>

int main() {
    try {
        // 逐渐增加内存使用量的容器
        std::vector<int*> memoryLeakSimulator;

        // 每次分配约10MB的内存
        const size_t allocationSize = 10 * 1024 * 1024 / sizeof(int);

        while (true) {
            int* memoryBlock = new int[allocationSize]; // 分配内存
            memoryLeakSimulator.push_back(memoryBlock); // 存入容器中以防止被释放

            std::cout << "Allocated 10MB. Current allocations: " << memoryLeakSimulator.size() * 10 << "MB." << std::endl;

            // 防止输出过快，可以添加一个小睡眠时间
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

            // 占用64GB内存（通常大多数计算机无法满足）
            if (memoryLeakSimulator.size() * 10 >= 1024 * 64) {
                std::cout << "Wow! You've reached 64GB memory allocation, crashing now..." << std::endl;
                break;
            }
        }
    } catch (std::exception e) { 
        std::cout << "Caught exception, possibly out of memory." << std::endl;
        std::cout << e.what() << std::endl;
    }

    return 0;
}
// 复制运行提示
// 隔离环境：尽量在一台可以承受崩溃的计算机上运行此程序，或者使用虚拟机中的受控环境。
// 数据安全：关闭所有其他重要的程序，将未保存的数据保存到持久化存储中。
// 复位手段：确保有一个可靠的复位或重启方式，如果系统变得非常缓慢，您可以立即采取行动进行恢复。
// 系统监控：可以打开任务管理器或资源监视器，观察内存使用情况，以在系统即将崩溃之前做出相应处理。
// 解释
// vector memoryLeakSimulator：用来存储每次分配的内存块指针，以防止它们被释放。
// allocationSize：计算每次大约分配10MB的整数数组大小。
// 循环：在无限循环中分配内存，并将其加入memoryLeakSimulator中。
// 输出：每次分配内存后，输出当前总共分配的内存量（以MB为单位）。
// 睡眠：添加了一个小睡眠时间，防止过快消耗内存。
// try-catch：捕获可能的异常，如内存不足从而导致new分配失败。
// 请保持谨慎，当你不再需要运行这个程序时，请停止其运行，以防对系统造成不良影响。