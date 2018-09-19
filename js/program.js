for (let i = 10; i >= 0; i -= 1) {
    document.writeln('Hello Word!');
}

let 你好 = '你好';
你好 = 'nihoa';
document.writeln(你好);

$(function () {
    let word = $('#word-edit #word-data').attr('value');
    word = $.parseJSON(word);

    $('#word-edit .edit').blur(function () {
        let $editItem = $(this);
        let name = $editItem.attr('name'),
            type = $editItem.data('type'),
            change = word;
        if (typeof(type) !== 'undefined') {
            if (type === 'sentences-en' || type === 'sentences-en') {
                let index = $editItem.data('index');
                if (word.sentences[index] === null) { // 值为空，使用索引取值后赋值都会出错，先赋值为空对象。
                    word.sentences[index] = {english: null};
                    word.sentences[index][name] = null;
                }
                change = word.sentences[index];
                // if ()
                if (type === 'sentences-en') {
                    if (change.english === null) {
                        change.english = {};
                        change.english[name] = null;
                    }
                    change = change.english;
                }
            } else {
                if (word[type] === null) {
                    word[type] = {};
                    word[type][name] = null;
                }
                change = word[type];
            }
        }
        change[name] = $editItem.val();
    })

    $('button#submit-word').click(function () {
        $.ajax({
            url: '/moma/bamboo-admin/dict/interns/word-edit/save',
            type: 'post',
            data: {word: word},
            processData: false,
            contentType: false,
            headers: {
                'X-CSRF-TOKEN': $('meta[name="csrf-token"]').attr('content')
            },
            dataType: 'json',
            success: function (data) {
                alert('Save Success!')
            }, error: function(){
                alert('Error!')
            }
        });

        return false
    })

});
// Function.prototype.method = function (name, func) {
//     this.prototype[name] = func;
//     return this;
// };

// // var a = 'a';

// function merge () {
//     var ret = {};
//     for (var i in arguments) {
//         var m = arguments[i];
//         for (var j in m) {
//             ret[j] = m[j];
//         }
//     }
//     return ret;
// }

// merge();

// .log(merge({a: 123}, {b: 456}));

// function() {
//   var varTest = 'test var OK.';
//   let letTest = 'test let OK.';

//   {
//     var varTest = 'varTest changed.';
//     let letTest = 'letTest changed.';
//   }

//   console.log(varTest); //输出"varTest changed."，内部"{}"中声明的varTest变量覆盖外部的letTest声明
//   console.log(letTest); //输出"test let OK."，内部"{}"中声明的letTest和外部的letTest不是同一个变量
// }());

const c = function fun() {
    let letTest = 'letTest.'
    {
        var varTest = 'varTest.';
        letTest = 'letTest changed.';
    }
    document.writeln(varTest); // 输出 varTest.
    document.writeln(letTest); // 输出undefined
};

c();
