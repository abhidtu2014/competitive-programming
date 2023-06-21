function removeAFromStr (str, index) {
    if (str.length === index) return '';
    const prefix = (str[index] === 'a') ? '' : str[index];
    return  prefix + removeAFromStr(str, index+1);
  }
  /* 
  console.log(removeAFromStr("baaaaccadaaabn", 0)) */
  
  
  function skipWordsFromString (str, word) {
      if (str.length === 0) return '';
    if (str.indexOf(word) === 0) {
        return skipWordsFromString(str.substring(word.length), word);
    } else {
        return str[0] + skipWordsFromString(str.substring(1), word);
    }
  }
  
  console.log(skipWordsFromString("baappleaaccadaaapplebn", "apple"))