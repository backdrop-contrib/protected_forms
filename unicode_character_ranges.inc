<?php

function _get_unicode_character_ranges() {
  // Have to use the Unicode Character Ranges since only some languages work with
  // $match = preg_match("/\p{$lang_script}/u", $randomChar); PCRE
  // explained on https://www.php.net/manual/en/regexp.reference.unicode.php
  $unicode_character_ranges = [
    'Adlam' => [
      '1E900 - 1E95F',
    ],
    'Ahom' => [
      '11700 - 1173F',
    ],
    'Anatolian Hieroglyphs' => [
      '14400 - 1467F',
    ],
    'Arabic' => [
      '0600 - 06FF',
      '0750 - 077F',
      '08A0 - 08FF',
      'FB50 - FDFF',
      'FE70 - FEFF',
      '10A80 - 10A9F',
      '10A60 - 10A7F',
    ],
    'Aramaic' => [
      '10840 - 1085F',
    ],
    'Armenian' => [
      '0530 - 058F',
      'FB00 - FB4F',
    ],
    'Avestan' => [
      '10B00 - 10B3F',
    ],
    'Balinese' => [
      '1B00 - 1B7F',
    ],
    'Bamum' => [
      'A6A0 - A6FF',
      '16800 - 16A3F',
    ],
    'Bassa Vah' => [
      '16AD0 - 16AFF',
    ],
    'Batak' => [
      '1BC0 - 1BFF',
    ],
    'Bengali and Assamese' => [
      '0980 - 09FF',
    ],
    'Bhaiksuki' => [
      '11C00 - 11C6F',
    ],
    'Bopomofo' => [
      '3100 - 312F',
      '31A0 - 31BF',
    ],
    'Brahmi' => [
      '11000 - 1107F',
    ],
    'Buginese' => [
      '1A00 - 1A1F',
    ],
    'Buhid' => [
      '1740 - 175F',
    ],
    'Canadian Aboriginal' => [
      '1400 - 167F',
      '18B0 - 18FF',
    ],
    'Carian' => [
      '102A0 - 102DF',
    ],
    'Caucasian Albanian' => [
      '10530 - 1056F',
    ],
    'Chakma' => [
      '11100 - 1114F',
    ],
    'Cham' => [
      'AA00 - AA5F',
    ],
    'Cherokee' => [
      '13A0 - 13FF',
      'AB70 - ABBF',
    ],
    'Chorasmian' => [
      '10FB0 - 10FDF',
    ],
    'CJK' => [
      '2E80 - 2EFF',
      '2F00 - 2FDF',
      '2FF0 - 2FFF',
      '3000 - 303F',
      '31C0 - 31EF',
      '3200 - 32FF',
      '3300 - 33FF',
      '3400 - 4DBF',
      '4E00 - 9FFC',
      'F900 - FAFF',
      'FE30 - FE4F',
      '20000 - 2A6DD',
      '2A700 - 2B734',
      '2B740 - 2B81D',
      '2B820 - 2CEA1',
      '2CEB0 - 2EBE0',
      '2F800 - 2FA1F',
      '30000 - 3134A',
    ],
    'Coptic' => [
      '2C80 - 2CFF',
      '0370 - 03FF',
      '102E0 - 102FF',
    ],
    'Cuneiform' => [
      '12000 - 123FF',
      '12400 - 1247F',
      '12480 - 1254F',
      '103A0 - 103DF',
      '10380 - 1039F',
    ],
    'Currency Symbols' => [
      '20A0 - 20CF',
    ],
    'Cypriot Syllabary' => [
      '10800 - 1083F',
    ],
    'Cyrillic' => [
      '0400 - 04FF',
      '0500 - 052F',
      '2DE0 - 2DFF',
      '1C80 - 1C8F',
    ],
    'Deseret' => [
      '10400 - 1044F',
    ],
    'Devanagari' => [
      '0900 - 097F',
      'A8E0 - A8FF',
    ],
    'Dives Akuru' => [
      '11900 - 1195F',
    ],
    'Dogra' => [
      '11800 - 1184F',
    ],
    'Egyptian Hieroglyphs' => [
      '13000 - 1342F',
      '13430 - 1343F',
    ],
    'Elbasan' => [
      '10500 - 1052F',
    ],
    'Elymaic' => [
      '10FE0 - 10FFF',
    ],
    'Ethiopic' => [
      '1200 - 137F',
      '1380 - 139F',
      '2D80 - 2DDF',
      'AB00 - AB2F',
    ],
    'Georgian' => [
      '10A0 - 10FF',
      '1C90 - 1CBF',
      '2D00 - 2D2F',
    ],
    'Glagolitic' => [
      '2C00 - 2C5F',
      '1E000 - 1E02F',
    ],
    'Gothic' => [
      '10330 - 1034F',
    ],
    'Grantha' => [
      '11300 - 1137F',
    ],
    'Greek' => [
      '0370 - 03FF',
      '1F00 - 1FFF',
      '10140 - 1018F',
    ],
    'Gujarati' => [
      '0A80 - 0AFF',
    ],
    'Gunjala Gondi' => [
      '11D60 - 11DAF',
    ],
    'Gurmukhi' => [
      '0A00 - 0A7F',
    ],
    'Hangul Jamo' => [
      '1100 - 11FF',
      'A960 - A97F',
      'D7B0 - D7FF',
      '3130 - 318F',
      'FF00 - FFEF',
    ],
    'Hangul Syllables' => [
      'AC00 - D7AF',
    ],
    'Hanifi Rohingya' => [
      '10D00 - 10D3F',
    ],
    'Hanunoo' => [
      '1720 - 173F',
    ],
    'Hatran' => [
      '108E0 - 108FF'
    ],
    'Hebrew' => [
      '0590 - 05FF',
      'FB00 - FB4F',
    ],
    'Hiragana' => [
      '3040 - 309F',
    ],
    'Javanese' => [
      'A980 - A9DF',
    ],
    'Kaithi' => [
      '11080 - 110CF',
    ],
    'Kana' => [
      '1B100 - 1B12F',
      '1B000 - 1B0FF',
      '1B130 - 1B16F',
    ],
    'Kanbun' => [
      '3190 - 319F',
    ],
    'Kannada' => [
      '0C80 - 0CFF',
    ],
    'Katakana' => [
      '30A0 - 30FF',
      '31F0 - 31FF',
      'FF00 - FFEF',
    ],
    'Kayah Li' => [
      'A900 - A92F',
    ],
    'Kharoshthi' => [
      '10A00 - 10A5F',
    ],
    'Khitan Small Script' => [
      '18B00 - 18CFF',
    ],
    'Khmer' => [
      '1780 - 17FF',
      '19E0 - 19FF',
    ],
    'Khojki' => [
      '11200 - 1124F',
    ],
    'Khudawadi' => [
      '112B0 - 112FF',
    ],
    'Lao' => [
      '0E80 - 0EFF',
    ],
    'Latin' => [
      '0000 - 007F',
      '0080 - 00FF',
      '0100 - 017F',
      '0180 - 024F',
      '0250 - 02AF',
      '02B0 - 02FF',
      '1D00 - 1D7F',
      '1D80 - 1DBF',
      '1E00 - 1EFF',
      '2000 - 206F',
      '2070 - 209F',
      '2100 - 214F',
      '2150 - 218F',
      '2C60 - 2C7F',
      'A720 - A7FF',
      'AB30 - AB6F',
      'FB00 - FB4F',
      'FF00 - FFEF',
    ],
    'Lepcha' => [
      '1C00 - 1C4F',
    ],
    'Limbu' => [
      '1900 - 194F',
    ],
    'Lisu' => [
      'A4D0 - A4FF',
      '11FB0 - 11FBF',
    ],
    'Lycian' => [
      '10280 - 1029F',
    ],
    'Lydian' => [
      '10920 - 1093F',
    ],
    'Mahajani' => [
      '11150 - 1117F'
    ],
    'Makasar' => [
      '11EE0 - 11EFF',
    ],
    'Malayalam' => [
      '0D00 - 0D7F',
    ],
    'Mandaic' => [
      '0840 - 085F',
    ],
    'Manichaean' => [
      '10AC0 - 10AFF',
    ],
    'Marchen' => [
      '11C70 - 11CBF',
    ],
    'Masaram Gondi' => [
      '11D00 - 11D5F',
    ],
    'Medefaidrin' => [
      '16E40 - 16E9F',
    ],
    'Meetei Mayek' => [
      'ABC0 - ABFF',
      'AAE0 - AAFF'
    ],
    'Mende Kikaku' => [
      '1E800 - 1E8DF',
    ],
    'Meroitic' => [
      '109A0 - 109FF',
      '10980 - 1099F',
    ],
    'Miao' => [
      '16F00 - 16F9F',
    ],
    'Miscellaneous Symbols' => [
      '2600 - 26FF',
    ],
    'Modi' => [
      '11600 - 1165F',
    ],
    'Modifier Letters' => [
      'A700 - A71F',
      '02B0 - 02FF',
    ],
    'Mongolian' => [
      '1800 - 18AF',
      '11660 - 1167F',
    ],
    'Mro' => [
      '16A40 - 16A6F',
    ],
    'Myanmar' => [
      '1000 - 109F',
      'AA60 - AA7F',
      'A9E0 - A9FF',
    ],
    'Multani' => [
      '11280 - 112AF',
    ],
    'Nabataean' => [
      '10880 - 108AF',
    ],
    'Nandinagari' => [
      '119A0 - 119FF',
    ],
    'New Tai Lue' => [
      '1980 - 19DF',
    ],
    'Newa' => [
      '11400 - 1147F',
    ],
    'Nko' => [
      '07C0 - 07FF',
    ],
    'Nushu' => [
      '1B170 - 1B2FF',
    ],
    'Nyiakeng Puachue Hmong' => [
      '1E100 - 1E14F',
    ],
    'Ogham' => [
      '1680 - 169F',
    ],
    'Ol Chiki' => [
      '1C50 - 1C7F',
    ],
    'Old Hungarian' => [
      '10C80 - 10CFF',
    ],
    'Old Italic' => [
      '10300 - 1032F',
    ],
    'Old Permic' => [
      '10350 - 1037F',
    ],
    'Old Persian' => [
      '103A0 - 103D',
    ],
    'Old Sogdian' => [
      '10F00 - 10F2F'
    ],
    'Old Turkic' => [
      '10C00 - 10C4F',
    ],
    'Oriya' => [
      '0B00 - 0B7F',
    ],
    'Osage' => [
      '104B0 - 104FF',
    ],
    'Osmanya' => [
      '10480 - 104AF',
    ],
    'Pahawh Hmong' => [
      '16B00 - 16B8F',
    ],
    'Pahlavi' => [
      '10B60 - 10B7F',
      '10B80 - 10BAF',
    ],
    'Palmyrene' => [
      '10860 - 1087F',
    ],
    'Parthian' => [
      '10B40 - 10B5F',
    ],
    'Pau Cin Hau' => [
      '11AC0 - 11AFF',
    ],
    'Phags Pa' => [
      'A840 - A87F',
    ],
    'Phoenician' => [
      '10900 - 1091F',
    ],
    'Rejang' => [
      'A930 - A95F',
    ],
    'Runic' => [
      '16A0 - 16FF',
    ],
    'Samaritan' => [
      '0800 - 083F',
    ],
    'Saurashtra' => [
      'A880 - A8DF',
    ],
    'Sharada' => [
      '11180 - 111DF',
    ],
    'Shavian' => [
      '10450 - 1047F',
    ],
    'Siddham' => [
      '11580 - 115FF',
    ],
    'Sinhala' => [
      '0D80 - 0DFF',
      '111E0 - 111FF',
    ],
    'Sogdian' => [
      '10F30 - 10F6F'
    ],
    'Sora Sompeng' => [
      '110D0 - 110FF',
    ],
    'Soyombo' => [
      '11A50 - 11AAF',
    ],
    'Sundanese' => [
      '1B80 - 1BBF',
      '1CC0 - 1CCF',
    ],
    'Superscripts and Subscripts' => [
      '2070 - 209F',
    ],
    'Syloti Nagri' => [
      'A800 - A82F',
    ],
    'Syriac' => [
      '0700 - 074F',
      '0860 - 086F',
    ],
    'Tagalog' => [
      '1700 - 171F',
    ],
    'Tagbanwa' => [
      '1760 - 177F',
    ],
    'Tai Le' => [
      '1950 - 197F',
    ],
    'Tai Tham' => [
      '1A20 - 1AAF',
    ],
    'Tai Viet' => [
      'AA80 - AADF',
    ],
    'Takri' => [
      '11680 - 116CF',
    ],
    'Tamil' => [
      '0B80 - 0BFF',
      '11FC0 - 11FFF',
    ],
    'Tangut' => [
      '17000 - 187F7',
      '18800 - 18AFF',
      '18D00 - 18D08',
    ],
    'Telugu' => [
      '0C00 - 0C7F',
    ],
    'Thaana' => [
      '0780 - 07BF',
    ],
    'Thai' => [
      '0E00 - 0E7F',
    ],
    'Tibetan' => [
      '0F00 - 0FFF',
    ],
    'Tifinagh' => [
      '2D30 - 2D7F',
    ],
    'Tirhuta' => [
      '11480 - 114DF',
    ],
    'Ugaritic' => [
      '10380 - 1039F',
    ],
    'Vai' => [
      'A500 - A63F',
    ],
    'Vedic Extensions' => [
      '1CD0 - 1CFF',
    ],
    'Wancho' => [
      '1E2C0 - 1E2FF',
    ],
    'Warang Citi' => [
      '118A0 - 118FF'
    ],
    'Yezidi' => [
      '10E80 - 10EBF',
    ],
    'Yi' => [
      'A000 - A48F',
      'A490 - A4CF',
    ],
    'Yijing' => [
      '4DC0 - 4DFF',
    ],
    'Zanabazar Square' => [
      '11A00 - 11A4F',
    ],
  ];
  ksort($unicode_character_ranges);
  return $unicode_character_ranges;
}
