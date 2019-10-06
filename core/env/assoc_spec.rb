require_relative 'env_spec_helper'

describe "ENV.assoc" do
  before :each do
    reserve_variables("foo" => "bar")
  end

  after :each do
    release_variables
  end

  it "returns an array of the key and value of the environment variable with the given key" do
    ENV.assoc("foo").should == ["foo", "bar"]
  end

  it "returns nil if no environment variable with the given key exists" do
    ENV.delete("foo")
    ENV.assoc("foo").should == nil
  end

  it "coerces a non-String name by calling #to_str" do
    mock_object = mock_to_str(:foo)
    ENV.assoc(mock_object).should == ["foo", "bar"]
  end

  it "raises TypeError if the argument is not a String and does not respond to #to_str" do
    -> { ENV.assoc(Object.new) }.should raise_error(TypeError)
  end
end
