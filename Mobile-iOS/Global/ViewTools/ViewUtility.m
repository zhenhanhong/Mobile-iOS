//
//  ViewUtility.m
//  StarCloud
//
//  Created by mac on 16/6/2.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "ViewUtility.h"

@implementation ViewUtility

//将UIColor变换为UIImage
+ (UIImage *)createImageWithColor:(UIColor *)color{
    CGRect rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    UIImage *theImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return theImage;
}

+ (UIView*)findFirstResponderBeneathView:(UIView*)view {
    // Search recursively for first responder
    for ( UIView *childView in view.subviews ) {
        if ( [childView respondsToSelector:@selector(isFirstResponder)] && [childView isFirstResponder] ) return childView;
        UIView *result = [self findFirstResponderBeneathView:childView];
        if ( result ) return result;
    }
    return nil;
}
+ (UIImage *)grabScreenImageWithIfTabController:(BOOL)ifTabController
{
    // 截屏
    if (iPhone6_Plus) {
        UIGraphicsBeginImageContextWithOptions(CGSizeMake(kScreenWidth*3, kScreenHeight*3), YES, 0);
    }
    else{
        UIGraphicsBeginImageContextWithOptions(CGSizeMake(kScreenWidth*2, kScreenHeight*2), YES, 0);
    }
    
    [[UIApplication sharedApplication].keyWindow.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *uiImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    //这里可以设置想要截图的区域
    CGImageRef imageRef = uiImage.CGImage;
    CGRect rect;
    if (iPhone6_Plus) {
        if (ifTabController == true) {
            rect = CGRectMake(0, 0, kScreenWidth*3, kScreenHeight*3 + kScreenWidth*3/375.f*133.f - TABBAR_HEIGHT*3);
        }
        else{
            rect = CGRectMake(0, 0, kScreenWidth*3, kScreenHeight*3 + kScreenWidth*3/375.f*133.f);
        }
    }
    else{
        if (ifTabController == true) {
            rect = CGRectMake(0, 0, kScreenWidth*2, kScreenHeight*2 + kScreenWidth*2/375.f*133.f - TABBAR_HEIGHT*2);
        }
        else{
            rect = CGRectMake(0, 0, kScreenWidth*2, kScreenHeight*2 + kScreenWidth*2/375.f*133.f);
        }
    }
    CGImageRef imageRefRect = CGImageCreateWithImageInRect(imageRef, rect);
    UIImage *sendImage = [[UIImage alloc] initWithCGImage:imageRefRect];
    
    return sendImage;
}
+ (UIImage *)grabScreen
{
    // 截屏
    if (iPhone6_Plus) {
        UIGraphicsBeginImageContextWithOptions(CGSizeMake(kScreenWidth*3, kScreenHeight*3), YES, 0);
    }
    else{
        UIGraphicsBeginImageContextWithOptions(CGSizeMake(kScreenWidth*2, kScreenHeight*2), YES, 0);
    }
    
    [[UIApplication sharedApplication].keyWindow.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *uiImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    //这里可以设置想要截图的区域
    CGImageRef imageRef = uiImage.CGImage;
    CGRect rect;
    if (iPhone6_Plus) {
        rect = CGRectMake(0, 0, kScreenWidth*3, kScreenHeight*3);
    }
    else{
        rect = CGRectMake(0, 0, kScreenWidth*2, kScreenHeight*2);
    }
    CGImageRef imageRefRect = CGImageCreateWithImageInRect(imageRef, rect);
    UIImage *sendImage = [[UIImage alloc] initWithCGImage:imageRefRect];
    
    return sendImage;
}
+ (void)drawCountDownButton:(UIButton *)button countTime:(int)countTime
{
    __block int timeout = countTime; //倒计时时间
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_source_t _timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, queue);
    dispatch_source_set_timer(_timer,dispatch_walltime(NULL, 0),1.0*NSEC_PER_SEC, 0); //每秒执行
    dispatch_source_set_event_handler(_timer, ^{
        if(timeout <= 0){ //倒计时结束，关闭
            dispatch_source_cancel(_timer);
            dispatch_async(dispatch_get_main_queue(), ^{
                [button setTitle:@"点击获取" forState:UIControlStateNormal];[button setBackgroundImage:[ViewUtility createImageWithColor:COLOR(245, 195, 86, 1)] forState:UIControlStateNormal];
                [button setTitleColor:COLOR(51, 51, 51, 1) forState:UIControlStateNormal];
                button.userInteractionEnabled = YES;
            });
        }else{
            int seconds = timeout % 60;
            NSString *strTime = [NSString stringWithFormat:@"%.2d", seconds];
            dispatch_async(dispatch_get_main_queue(), ^{
                button.titleLabel.text = [NSString stringWithFormat:@"还剩%@秒",strTime];
                [button setTitle:[NSString stringWithFormat:@"还剩%@秒",strTime] forState:UIControlStateNormal];
                [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
                [button setBackgroundImage:[ViewUtility createImageWithColor:COLOR(204, 204, 204, 1)] forState:UIControlStateNormal];
                button.userInteractionEnabled = NO;
            });
            timeout--;
        }
    });
    dispatch_resume(_timer);
}
@end
