/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {

    let a = 0, b = a + 1;

    while(a < nums.length)
    {
        while (b < nums.length)
        {
            if(nums[a] + nums[b] === target)
            {
                return [a, b];
            }
            
            b++;
        }
        b = ++a + 1;
    }
};
