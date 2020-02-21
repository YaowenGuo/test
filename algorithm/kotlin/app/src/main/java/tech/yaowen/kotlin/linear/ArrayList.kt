package tech.yaowen.kotlin.linear


public class ArrayList<D>(d: D) {

    private var _incrementTime = 0
    private var data: Array<Any>

    companion object {
        const val LIST_INSREMETN_SIZE = 10
    }

    init {
        data = Array<Any>(LIST_INSREMETN_SIZE) {
            d as Any
        }
    }

    /**
     * 创建空线性表
     */
    fun initList() {

    }

    /**
     * 销毁线性表
     */
    fun destroyList() {

    }

    /**
     * 清空线性表
     */
    fun clear() {

    }

    /**
     * 是否为空表
     */
    fun isEmpty() {

    }

    /**
     * 表长
     */
    fun length() {

    }

    /**
     * 获取元素
     */

    operator fun get(i: Int): D {
        return data[i] as D
    }

    /**
     * 判断某元素的位置, compare 为判断条件
     */

    fun indexOf(d: D, compare: (d: D, find: D) -> Boolean) {

    }


    /**
     * 插入节点
     */
    fun insert(d: D, index: Int = -1) {

    }

    /**
     * 删除节点
     */

    fun delete(index: Int): D {
        return data[index] as D
    }

    /**
     * 遍历
     */

    fun traverse(visit: (d: D) -> Unit): Boolean {
        return false
    }
}

fun main() {

}