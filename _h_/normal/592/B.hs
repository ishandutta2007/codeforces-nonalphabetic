main = fmap ((^2) . subtract (2::Integer) . read) getLine >>= print