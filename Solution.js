
/**
 * @param {number} targetNumberOfDigits
 * @return {string[]}
 */
var findStrobogrammatic = function (targetNumberOfDigits) {
    this.strobogrammaticPairs = [['0', '0'], ['1', '1'], ['6', '9'], ['8', '8'], ['9', '6']];
    return findStrobogrammaticNumber(targetNumberOfDigits, targetNumberOfDigits);
};

/**
 * @param {number} currentNumberOfDigits
 * @param {number} targetNumberOfDigits
 * @return {string[]}
 */
function findStrobogrammaticNumber(currentNumberOfDigits, targetNumberOfDigits) {
    if (currentNumberOfDigits === 0) {
        return [""];
    }
    if (currentNumberOfDigits === 1) {
        return ["0", "1", "8"];
    }
    const priorStrobogrammatic = findStrobogrammaticNumber(currentNumberOfDigits - 2, targetNumberOfDigits);
    const currentStrobogrammatic = [];

    for (const previous of priorStrobogrammatic) {
        for (const pair of this.strobogrammaticPairs) {
            if (pair[0] !== '0' || currentNumberOfDigits < targetNumberOfDigits) {
                currentStrobogrammatic.push(pair[0] + previous + pair[1]);
            }
        }
    }
    return currentStrobogrammatic;
}
