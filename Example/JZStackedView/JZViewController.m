//
//  JZViewController.m
//  JZStackedView
//
//  Created by James Zammit on 08/15/2015.
//  Copyright (c) 2015 James Zammit. All rights reserved.
//

#import "JZViewController.h"
#import "JZStackedView.h"

@interface JZViewController () <JZDataSource, JZDelegate>

@property (nonatomic, strong) IBOutlet JZ *JZStackedView;

@end

@implementation JZViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	
    // Generate User Interface
    [self GenerateMainUI];
}

-(void)GenerateMainUI
{
    // Set Status Bar Light
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
    [[UIApplication sharedApplication] setStatusBarHidden:NO];
    
    // Set Background Colour
    [self.view setBackgroundColor:[UIColor colorWithRed:57.0/255.0f green:204.0/255.0f blue:219.0/255.0f alpha:1.0f]];
    
    // Initialize JZStackedView
    _JZStackedView = [[JZ alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height * 0.75)];
    _JZStackedView.delegate = self;
    _JZStackedView.dataSource = self;
    [_JZStackedView setCenter:CGPointMake(self.view.frame.size.width * 0.5, self.view.frame.size.height * 0.5)];
    _JZStackedView.bounces = YES;
    _JZStackedView.scrollSpeed = 0.85f;
    _JZStackedView.vertical = YES;
    _JZStackedView.bounceDistance = 0.4f;
    _JZStackedView.pagingEnabled = YES;
    _JZStackedView.ignorePerpendicularSwipes = YES;
    [_JZStackedView scrollToItemAtIndex:2 animated:YES];
    [self.view addSubview:_JZStackedView];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (NSInteger)numberOfItemsInJZStackedView:(JZ *)JZStackedView
{
    return 3;
}

- (UIView *)JZStackedView:(JZ *)JZStackedView viewForItemAtIndex:(NSInteger)index reusingView:(UIView *)view
{
    
    
    //create new view if no view is available for recycling
    if (view == nil)
    {
        // Create New Objects here
        view = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width * 0.9, self.view.frame.size.height * 0.71)];
        [view setBackgroundColor:[UIColor whiteColor]];
        view.layer.cornerRadius = 5.0f;
        view.contentMode = UIViewContentModeCenter;
        
        UIBezierPath *shadowPath = [UIBezierPath bezierPathWithRect:view.bounds];
        view.layer.masksToBounds = NO;
        view.layer.shadowColor = [UIColor blackColor].CGColor;
        view.layer.shadowOffset = CGSizeMake(0.0f, 3.0f);
        view.layer.shadowOpacity = 0.2f;
        view.layer.shadowPath = shadowPath.CGPath;
    }
    return view;
}

- (void)JZStackedViewCurrentItemIndexDidChange:(JZ *)JZStackedView
{
    if ([JZStackedView.visibleItemViews count] > 0)
    {
        UIView *view0 = JZStackedView.visibleItemViews[0];
        
        
        
        [UIView animateWithDuration:0.35
                         animations:^{
                             
                             view0.alpha = 0.25f;
                         }
                         completion:^(BOOL finished){
                             
                             
                         }];
        
        
    }
    
    if ([JZStackedView.visibleItemViews count] >= 2)
    {
        UIView *view1 = JZStackedView.visibleItemViews[1];
        
        
        [UIView animateWithDuration:0.35
                         animations:^{
                             
                             view1.alpha = 0.45f;
                         }
                         completion:^(BOOL finished){
                             
                             
                         }];
        
    }
    
    if ([JZStackedView.visibleItemViews count] == 3)
    {
        UIView *view2 = JZStackedView.visibleItemViews[2];
        
        
        [UIView animateWithDuration:0.35
                         animations:^{
                             
                             view2.alpha = 1.0f;
                         }
                         completion:^(BOOL finished){
                             
                             
                         }];
    }
    
    if ([JZStackedView.visibleItemViews count] > 0)
    {
        
        [UIView animateWithDuration:0.35
                         animations:^{
                             
                             JZStackedView.currentItemView.alpha = 1.0f;
                         }
                         completion:^(BOOL finished){
                             
                             
                         }];
        
    }
}

- (CGFloat)JZStackedView:(JZ *)JZStackedView valueForOption:(JZOption)option withDefault:(CGFloat)value
{
    if (option == JZOptionSpacing)
    {
        return 0.17f;
    }
    
    if (option == JZOptionTilt)
    {
        return 0.15f;
    }
    return value;
}


@end
