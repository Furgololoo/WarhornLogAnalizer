#include "scopedtimer.h"
#include <QDebug>

ScopedTimer::ScopedTimer(std::string_view function) : functionName(function), start(std::chrono::steady_clock::now()) {}

ScopedTimer::~ScopedTimer()
{
    std::chrono::time_point end = std::chrono::steady_clock::now();
    qDebug() << functionName << " take: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
             << " ms";
}
