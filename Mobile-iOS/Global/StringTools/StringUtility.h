//
//  StringUtility.h
//  StarCloud
//
//  Created by mac on 16/6/3.
//  Copyright © 2016年 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface StringUtility : NSObject
// base64加密
+ (NSString *)base64EncodingWithString:(NSString *)oringinString;
// base64解密
+ (NSString *)getOringinStringWithBase64String:(NSString *)string;
// 转换字符串单位：（亿、万）
+ (NSString *)changeUnitWithOringinString:(NSString *)oringinString;
// 转换成百分数
+ (NSString *)changeNumberToPercentWithNum:(NSNumber *)num;
// 日历标题赋值
+ (NSAttributedString *)getResultAttributeStringWithDateString:(NSString *)dateString;
// 将单位（千）转换成单位（万）
+ (NSString *)getFormatThousandString:(NSString *)oriString;
// 有几位小数显示几位小数，没有小数则去掉小数位
+ (NSString *)changeFloat:(double)stringRef;

// 取某个字符在字符串的位置
+ (NSNumber *)checkCharactorIndexOfString:(NSString *)string WithIndexString:(NSString *)indexString;
//加密接口参数
+ (NSString *)srcretString;
//判断电话号码
+ (BOOL)isVaildPhoneNum:(NSString *)phoneNum;
@end
