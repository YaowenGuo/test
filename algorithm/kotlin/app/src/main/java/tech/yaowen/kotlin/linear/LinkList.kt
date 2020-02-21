package tech.yaowen.kotlin.linear

/**
 * 创建空线性表
 */

public class LinkList<D>() {

    private var data: D? = null
    private var next: LinkList<D>? = null

    private val head = this

     private constructor(d: D): this() {
         data = d
     }

    /**
     * 清空线性表
     */
    fun clear() {
        next = null
    }

    /**
     * 是否为空表
     */
    fun isEmpty(): Boolean {
        return next == null
    }

    /**
     * 表长
     */
    fun length(): Int {
        var len = 0
        var p: LinkList<D> = this
        while(p.next != null) {
            len += 1
            p = p.next!!
        }
        return len
    }

    /**
     * 获取元素
     */

    operator fun get(index: Int): D? {
        var p = next
        var i = 0
        while (p != null && i < index ) {
            p = p.next
            i += 1
        }

        return p?.data
    }

    /**
     * 判断某元素的位置, compare 为判断条件
     */

    fun indexOf(d: D, compare: (d: D?, find: D?) -> Boolean): Int {
        var p = this
        var index = -1
        var find = false
        while (p.next != null) {
            index += 1
            p = p.next!!
            if (d == p.data || compare(d, p.data)) {
                find = true
                break
            }
        }


        return if (find) index else -1
    }

    /**
     * 前一个节点
     */
    fun priorElem(d: D?, equal: (d: D?, find: D?) -> Boolean): D? {

        var priorP: LinkList<D>? = null
        var p: LinkList<D>? = head.next
        while (p != null && !equal(d, p.data)) {
            priorP = p
            p = p.next
        }
        return priorP?.data
    }

    /**
     * 下一个节点
     */

    fun nextElem(d: D, equal: (d: D, find: D?) -> Boolean): D? {
        var p: LinkList<D>? = head.next
        while (p != null && !equal(d, p.data)) {
            p = p.next
        }
        return p?.next?.data
    }

    /**
     * 插入节点
     */
    fun insert(d: D, index: Int = 0) {
        var i = 0
        var priorP: LinkList<D> = this
        var p: LinkList<D>? = head.next
        while (p != null && i < index) {
            i += 1
            priorP = p
            p = p.next
        }
        val node = LinkList<D>(d)
        node.next = p
        priorP.next = node
    }

    /**
     * 删除节点
     */

    fun delete(index: Int): D? {
        var i = 0
        var priorP: LinkList<D> = this
        var p: LinkList<D>? = head.next
        while (p != null && i < index) {
            i += 1
            priorP = p
            p = p.next
        }
        if (i == index) {
            priorP.next = p?.next
            p?.next = null
        }
        return p?.data
    }

    /**
     * 遍历
     */

    fun traverse(visit: (d: D) -> Unit) {
        var p = next
        while(p != null) {
            p.data?.let(visit)
            p = p.next
        }
    }

}

fun main() {

    val intLink = LinkList<Int>()
    for (i in 5 downTo 0) {
        intLink.insert(i)
    }

    // 输出
    println("Original")
    intLink.traverse {
        println(it)
    }
    println("Length: ${intLink.isEmpty()}")
    intLink.clear()
    println("Length: ${intLink.isEmpty()}")

}