
Pod::Spec.new do |s|
  s.name             = "JZStackedView"
  s.version          = "0.1.0"
  s.summary          = "JZStackedView is a 3d stacked view that compliments carousel."
  s.homepage         = "https://github.com/zammitjames/JZStackedView"
  s.license          = { :type => 'BSD' }
  s.author           = { "James Zammit" => "jameszammit@gmail.com" }
  s.source           = { :git => "https://github.com/zammitjames/JZStackedView.git", :tag => '0.1.0'}

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes/JZStackedView.{h,m}'

end
