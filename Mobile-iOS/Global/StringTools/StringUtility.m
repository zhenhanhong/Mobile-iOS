//
//  StringUtility.m
//  StarCloud
//
//  Created by mac on 16/6/3.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "StringUtility.h"

@implementation StringUtility

+ (NSString *)base64EncodingWithString:(NSString *)oringinString{
    NSData *originData = [oringinString dataUsingEncoding:NSASCIIStringEncoding];
    NSString *encodeResult = [originData base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
    return encodeResult;
}
+ (NSString *)getOringinStringWithBase64String:(NSString *)string{
    NSData *decodeData = [[NSData alloc] initWithBase64EncodedString:string options:0];
    NSString *decodeStr = [[NSString alloc] initWithData:decodeData encoding:NSASCIIStringEncoding];
    return decodeStr;
}
+ (NSString *)changeUnitWithOringinString:(NSString *)oringinString
{
    NSString *alterString;
    NSString *resultString;
    NSInteger index = [[self checkCharactorIndexOfString:oringinString WithIndexString:@"."] integerValue];
    // 如果包含小数点
    if ([oringinString containsString:@"."]) {
        alterString = [oringinString substringToIndex:index-1];
    }
    else{
        alterString = oringinString;
    }
    if (alterString.length > 8) {
        NSString *intArea = [alterString substringToIndex:alterString.length-8];
        NSString *floatArea = [alterString substringWithRange:NSMakeRange(alterString.length-8, 1)];
        NSString *subFloatArea = [alterString substringWithRange:NSMakeRange(alterString.length-7, 1)];
        if (subFloatArea.intValue >= 5) {
            floatArea = [NSString stringWithFormat:@"%d",[floatArea intValue]+1];
            if (floatArea.length > 1) {
                intArea = [NSString stringWithFormat:@"%d",[intArea intValue]+1];
                resultString = [NSString stringWithFormat:@"%@亿",intArea];
            }
            else{
                resultString = [NSString stringWithFormat:@"%@.%@亿",intArea,floatArea];
            }
        }
        else{
            if ([floatArea isEqualToString:@"0"]) {
                resultString = [NSString stringWithFormat:@"%@亿",intArea];
            }
            else{
                resultString = [NSString stringWithFormat:@"%@.%@亿",intArea,floatArea];
            }
        }
    }
    else if (alterString.length > 4) {
        NSString *intArea = [alterString substringToIndex:alterString.length-4];
        NSString *floatArea = [alterString substringWithRange:NSMakeRange(alterString.length-4, 1)];
        NSString *subFloatArea = [alterString substringWithRange:NSMakeRange(alterString.length-3, 1)];
        if (subFloatArea.intValue >= 5) {
            floatArea = [NSString stringWithFormat:@"%d",[floatArea intValue]+1];
            if (floatArea.length > 1) {
                intArea = [NSString stringWithFormat:@"%d",[intArea intValue]+1];
                resultString = [NSString stringWithFormat:@"%@万",intArea];
            }
            else{
                resultString = [NSString stringWithFormat:@"%@.%@万",intArea,floatArea];
            }
        }
        else{
            if ([floatArea isEqualToString:@"0"]) {
                resultString = [NSString stringWithFormat:@"%@万",intArea];
            }
            else{
                resultString = [NSString stringWithFormat:@"%@.%@万",intArea,floatArea];
            }
        }
    }
    else{
        if ([alterString isEqualToString:oringinString]) {
            resultString = oringinString;
        }
        else{
            NSString *intArea = alterString;
            NSString *floatArea = [oringinString substringWithRange:NSMakeRange(index, 1)];
            NSString *subFloatArea;
            if (index != oringinString.length - 1) {
                subFloatArea = [oringinString substringWithRange:NSMakeRange(index+1, 1)];
            }
            if (subFloatArea.intValue >= 5) {
                floatArea = [NSString stringWithFormat:@"%d",[floatArea intValue]+1];
                if (floatArea.length > 1) {
                    resultString = [NSString stringWithFormat:@"%@",intArea];
                }
                else{
                    resultString = [NSString stringWithFormat:@"%@.%@",intArea,floatArea];
                }
            }
            else{
                if ([floatArea isEqualToString:@"0"]) {
                    resultString = [NSString stringWithFormat:@"%@",intArea];
                }
                else{
                    resultString = [NSString stringWithFormat:@"%@.%@",intArea,floatArea];
                }
            }
        }
    }
    return resultString;
}
+ (NSString *)changeNumberToPercentWithNum:(NSNumber *)num{
    if (IsNilOrNull(num)) {
        return @"-";
    }
    NSString *formatNo = [[NSNumber numberWithDouble:[num doubleValue]*100] stringValue];
    if ([formatNo containsString:@"."]) {
        NSInteger index = [[self checkCharactorIndexOfString:formatNo WithIndexString:@"."] integerValue];
        NSString *intArea = [formatNo substringToIndex:index-1];
        NSString *floatArea = [formatNo substringFromIndex:index];
        if (floatArea.length == 1) {
            return [NSString stringWithFormat:@"%@%@",formatNo,@"%"];
        }
        else if (floatArea.length >= 2) {
            NSString *float1 = [floatArea substringToIndex:1];
            NSString *float2 = [floatArea substringWithRange:NSMakeRange(1, 1)];
            if ([float2 intValue] >= 5) {
                float1 = [NSString stringWithFormat:@"%d",[float1 intValue] + 1];
                if (float1.length > 1) {
                    if ([intArea containsString:@"-"]) {
                        intArea = [NSString stringWithFormat:@"%d",[intArea intValue]-1];
                    }
                    else{
                        intArea = [NSString stringWithFormat:@"%d",[intArea intValue]+1];
                    }
                    float1 = [float1 substringFromIndex:1];
                    if ([float1 isEqualToString:@"0"]) {
                        return [NSString stringWithFormat:@"%@%@",intArea,@"%"];
                    }
                    else{
                        return [NSString stringWithFormat:@"%@.%@%@",intArea,float1,@"%"];
                    }
                }
                else{
                    if ([float1 isEqualToString:@"0"]) {
                        return [NSString stringWithFormat:@"%@%@",intArea,@"%"];
                    }
                    else{
                        return [NSString stringWithFormat:@"%@.%@%@",intArea,float1,@"%"];
                    }
                }
            }
            else{
                if ([float1 isEqualToString:@"0"]) {
                    return [NSString stringWithFormat:@"%@%@",intArea,@"%"];
                }
                else{
                    return [NSString stringWithFormat:@"%@.%@%@",intArea,float1,@"%"];
                }
            }
        }
    }
    else{
        return [NSString stringWithFormat:@"%@%@",formatNo,@"%"];
    }
    
    return [NSString stringWithFormat:@"%@%@",formatNo,@"%"];
}
// 千 -> 万
+ (NSString *)getFormatThousandString:(NSString *)oriString
{
    if ([oriString isEqualToString:@"0"]) {
        return @"0";
    }
    // 整数位
    int intArea = 0;
    // 一位小数位
    int floatArea = [[oriString substringToIndex:1] intValue];
    // 二位小数位
    int subFloatArea = [[oriString substringWithRange:NSMakeRange(1, 1)] intValue];
    
    if (oriString.length <= 4) {
        if (floatArea == 9) {
            if (subFloatArea >= 5) {
                floatArea = 0;
                intArea += 1;
            }
        }
        else{
            if (subFloatArea >= 5) {
                floatArea += 1;
            }
        }
    }
    
    NSString *resultString;
    if (floatArea == 0) {
        resultString = [NSString stringWithFormat:@"%d",intArea];
    }
    else{
        resultString = [NSString stringWithFormat:@"%d.%d",intArea,floatArea];
    }
    return resultString;
}
+ (NSString *)changeFloat:(double)stringRef{
    float judgePrice = roundf(stringRef);
    NSString * outNumber;
    if (stringRef == judgePrice) {
        //如果是整数
        outNumber = [NSString stringWithFormat:@"%0.0f", stringRef];
    }else{
        //如果不是整数
        NSString * testNumber = [NSString stringWithFormat:@"%.2f",stringRef];
        NSString * s = nil;
        long offset = testNumber.length - 1;
        while (offset)
        {
            s = [testNumber substringWithRange:NSMakeRange(offset, 1)];
            if ([s isEqualToString:@"0"] || [s isEqualToString:@"."])
            {
                offset--;
            }
            else
            {
                break;
            }
        }
        outNumber = [testNumber substringToIndex:offset+1];
    }
    return outNumber;
}
+ (NSNumber *)checkCharactorIndexOfString:(NSString *)string WithIndexString:(NSString *)indexString{
    NSString *temp = nil;
    for(int i =0; i < [string length]; i++)
    {
        temp = [string substringWithRange:NSMakeRange(i, 1)];
        if ([temp isEqualToString:indexString]) {
            return [NSNumber numberWithInt:i+1];
        }
    }
    return nil;
}

+(NSString *)srcretString{
    NSData* originData = [SERVER_USERPSD dataUsingEncoding:NSASCIIStringEncoding];
    NSString* encodeResult = [originData base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
    NSString * resultStr = [NSString stringWithFormat:@"Basic %@",encodeResult];
    return resultStr;
}
+ (BOOL)isVaildPhoneNum:(NSString *)phoneNum{
    NSString *regex = @"1[3|4|5|7|8|][0-9]{9}";
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    BOOL isValid = [predicate evaluateWithObject:phoneNum];
    return isValid;
}
+ (NSAttributedString *)getResultAttributeStringWithDateString:(NSString *)dateString
{
    NSMutableAttributedString *stringTitle = [[NSMutableAttributedString alloc] init];
    
    NSTextAttachment *attach1 = [[NSTextAttachment alloc] init];
    attach1.image = [UIImage imageNamed:@"current_date_icon"];
    attach1.bounds = CGRectMake(0, -1, 12, 12);
    NSAttributedString *attachString1 = [NSAttributedString attributedStringWithAttachment:attach1];
    
    NSTextAttachment *attach2 = [[NSTextAttachment alloc] init];
    attach2.image = [UIImage imageNamed:@"behand_day_icon"];
    attach2.bounds = CGRectMake(0, -1, 4.5f, 9);
    NSAttributedString *attachString2 = [NSAttributedString attributedStringWithAttachment:attach2];
    
    [stringTitle appendAttributedString:attachString1];
    [stringTitle appendAttributedString:[[NSAttributedString alloc] initWithString:[NSString stringWithFormat:@"  %@ ",dateString]]];
    [stringTitle appendAttributedString:attachString2];
    
    return stringTitle;
}
@end
