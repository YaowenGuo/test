package tech.yaowen.kotlin.coroutines

import kotlinx.coroutines.*
import kotlinx.coroutines.Dispatchers.IO
import kotlin.concurrent.thread


val repeatFun: String.(Int) -> String = { times -> this.repeat(times) }
val twoParameters: (String, Int) -> String = repeatFun // OK

fun runTransformation(f: (String, Int) -> String): String {
    return f("hello", 3)
}
val result = runTransformation(repeatFun) // OK




class Test {

    operator fun get(value: String): String {

        return "aa"
    }

    operator fun invoke(value: Int) {
        print("value:" + value)
    }


}

class Add {
    var sum = 0
    operator fun invoke(num: Int) {
        sum += num
    }
}



fun test() {
    var add = Add()
    add(5)
}


val a = { i: Int -> i + 1 } // 推断出的类型是 (Int) -> Int

fun main() = runBlocking<Unit> {
//    println(intFunction(2))

    GlobalScope.launch(Dispatchers.Main) {
        val orders = withContext(Dispatchers.Default) {
            print("ds")
        }
        print(orders)
    }

    asyncUI {
        // 假设这是两个不同的 api 请求
        val deferred1 = bg {
            Server.getApiStore().login("173176360", "123456").execute()
        }

        val deferred2 = bg {
            Server.getApiStore().login("173176360", "123456").execute()
        }

        // 后台请求着 api，此时我还可以在 UI 协程中做我想做的事情
        textView.text = "loading"
        delay(5, TimeUnit.SECONDS)

        // 等 UI 协程中的事情做完了，专心等待 api 请求完成（其实 api 请求有可能已经完成了）
        // 通过提供 ExceptionHandleType 进行异常的过滤
        val response = deferred1.wait(TOAST)
        deferred2.wait(THROUGH) // deferred2 的结果我不关心

        // 此时两个请求肯定都完成了，并且 deferred1 没有异常发生
        textView.text = response.toString()
    }

}