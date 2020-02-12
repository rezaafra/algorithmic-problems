using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Diagnostics.Tracing;
using System.Linq;
using System.Text;

namespace RA
{
    class Anagram
    {
        public static List<List<string>> find(List<string> strList)
        {
            var anagrams = new List<List<string>>();
            var anagramsTable = new Dictionary<string, List<string>>();
            foreach (string str in strList)
            {
                var sortedStr = string.Concat(str.OrderBy(c => c));
                string.Concat(sortedStr.OrderBy(c => c));
                if (anagramsTable.ContainsKey(sortedStr))
                {
                    anagramsTable[sortedStr].Add(str);
                }
                else
                {
                    var values = new List<string>();
                    values.Add(str);
                    anagramsTable.Add(sortedStr, values);
                }
            }

            foreach (var pair in anagramsTable)
            {    
                anagrams.Add(pair.Value);
            }
            return anagrams;
        }

        static void Main(string[] args)
        {
            var words = new List<string>();
            words.Add("ACT");
            words.Add("CAT");
            words.Add("TAC");

            var anagrams = find(words);
            foreach (var sublist in anagrams)
            {
                foreach (var item in sublist)
                Console.Write(item + " ");
            }
        }
    }   
}












