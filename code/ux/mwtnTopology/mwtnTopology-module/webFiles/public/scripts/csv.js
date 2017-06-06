/*! htSolutionsPublic - v1.0.0 - 2015-08-09
* http://www.highstreet-technologies.com
* Copyright (c) 2015 highstreet technologies GmbH; Licensed Apache-2.0 */
!function(){"use strict";var a={};a.RELAXED=!1,a.IGNORE_RECORD_LENGTH=!1,a.IGNORE_QUOTES=!1,a.LINE_FEED_OK=!0,a.CARRIAGE_RETURN_OK=!0,a.DETECT_TYPES=!0,a.IGNORE_QUOTE_WHITESPACE=!0,a.DEBUG=!1,a.COLUMN_SEPARATOR=",",a.ERROR_EOF="UNEXPECTED_END_OF_FILE",a.ERROR_CHAR="UNEXPECTED_CHARACTER",a.ERROR_EOL="UNEXPECTED_END_OF_RECORD",a.WARN_SPACE="UNEXPECTED_WHITESPACE";var b='"',c="\r",d="\n",e=" ",f="	",g=0,h=1,i=2,j=4;a.parse=function(j){var k=a.result=[];a.offset=0,a.str=j,a.record_begin(),a.debug("parse()",j);for(var l;;){if(l=j[a.offset++],a.debug("c",l),null==l){a.escaped&&a.error(a.ERROR_EOF),a.record&&(a.token_end(),a.record_end()),a.debug("...bail",l,a.state,a.record),a.reset();break}if(null==a.record){if(a.RELAXED&&(l==d||l==c&&j[a.offset+1]==d))continue;a.record_begin()}if(a.state==g){if((l===e||l===f)&&a.next_nonspace()==b){if(a.RELAXED||a.IGNORE_QUOTE_WHITESPACE)continue;a.warn(a.WARN_SPACE)}if(l==b&&!a.IGNORE_QUOTES){a.debug("...escaped start",l),a.escaped=!0,a.state=h;continue}a.state=h}a.state==h&&a.escaped?l==b?j[a.offset]==b?(a.debug("...escaped quote",l),a.token+=b,a.offset++):(a.debug("...escaped end",l),a.escaped=!1,a.state=i):(a.token+=l,a.debug("...escaped add",l,a.token)):l==c?(j[a.offset]==d?a.offset++:a.CARRIAGE_RETURN_OK||a.error(a.ERROR_CHAR),a.token_end(),a.record_end()):l==d?(a.LINE_FEED_OK||a.RELAXED||a.error(a.ERROR_CHAR),a.token_end(),a.record_end()):l==a.COLUMN_SEPARATOR?a.token_end():a.state==h?(a.token+=l,a.debug("...add",l,a.token)):l===e||l===f?a.IGNORE_QUOTE_WHITESPACE||a.error(a.WARN_SPACE):a.RELAXED||a.error(a.ERROR_CHAR)}return k},a.json=function(){var a=new require("stream").Transform({objectMode:!0});return a._transform=function(b,c,d){a.push(JSON.stringify(b.toString())+require("os").EOL),d()},a},a.stream=function(){var b=new require("stream").Transform({objectMode:!0});return b.EOL="\n",b.prior="",b.emitter=function(b){return function(c){b.push(a.parse(c+b.EOL))}}(b),b._transform=function(a,b,c){var d=""==this.prior?a.toString().split(this.EOL):(this.prior+a.toString()).split(this.EOL);this.prior=d.pop(),d.forEach(this.emitter),c()},b._flush=function(a){""!=this.prior&&(this.emitter(this.prior),this.prior=""),a()},b},a.reset=function(){a.state=null,a.token=null,a.escaped=null,a.record=null,a.offset=null,a.result=null,a.str=null},a.next_nonspace=function(){for(var b,c=a.offset;c<a.str.length;)if(b=a.str[c++],b!=e&&b!==f)return b;return null},a.record_begin=function(){a.escaped=!1,a.record=[],a.token_begin(),a.debug("record_begin")},a.record_end=function(){a.state=j,!a.IGNORE_RECORD_LENGTH&&!a.RELAXED&&a.result.length>0&&a.record.length!=a.result[0].length&&a.error(a.ERROR_EOL),a.result.push(a.record),a.debug("record end",a.record),a.record=null},a.resolve_type=function(a){return a.match(/^\d+(\.\d+)?$/)?a=parseFloat(a):a.match(/^(true|false)$/i)?a=Boolean(a.match(/true/i)):"undefined"===a?a=void 0:"null"===a&&(a=null),a},a.token_begin=function(){a.state=g,a.token=""},a.token_end=function(){a.DETECT_TYPES&&(a.token=a.resolve_type(a.token)),a.record.push(a.token),a.debug("token end",a.token),a.token_begin()},a.debug=function(){a.DEBUG&&console.log(arguments)},a.dump=function(b){return[b,"at char",a.offset,":",a.str.substr(a.offset-50,50).replace(/\r/gm,"\\r").replace(/\n/gm,"\\n").replace(/\t/gm,"\\t")].join(" ")},a.error=function(b){var c=a.dump(b);throw a.reset(),c},a.warn=function(b){var c=a.dump(b);try{return void console.warn(c)}catch(d){}try{console.log(c)}catch(d){}},function(a,b,c){var d;"undefined"!=typeof module&&module.exports?module.exports=c():"function"==typeof d&&"object"==typeof d.amd?d(c):b[a]=c()}("CSV",Function("return this")(),function(){return a})}();