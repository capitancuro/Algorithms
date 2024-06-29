/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let val = x.toString();
    let a = 0, b = val.length - 1;
    let pal = true;

    while (a < val.length)
    {
        if(val[a] !== val[b])
        {
            pal = false;
        }
        a++;
        b--;
    }
    
    return pal;
};
